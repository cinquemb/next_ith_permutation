#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/multiprecision/number.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/special_functions/round.hpp>
#include <boost/math/special_functions/log1p.hpp>
#include <boost/math/special_functions/beta.hpp>
#include <boost/lexical_cast.hpp>
//clang++ -Os -std=c++11 -pedantic next_ith_permutation.cpp -o next_ith_permutation
//clang++ -S -mllvm --x86-asm-syntax=intel generate_permutations.cpp -o generate_permutations.asm

//usage: ./next_ith_permutation 128 32 "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0" 0


typedef std::basic_ostringstream<char> ostringstream;
typedef std::basic_istringstream<char> istringstream;
typedef boost::multiprecision::number<boost::multiprecision::cpp_dec_float<0> > mp_type;

boost::multiprecision::cpp_int power_of(boost::multiprecision::cpp_int& base, boost::multiprecision::cpp_int& exponent){
  int range = boost::lexical_cast<int>(exponent);
  boost::multiprecision::cpp_int n1(1);

  for(int i=0;i<range;i++){
    n1 = n1 * base;
  }

  return n1;
}

std::vector<int> right_rotation(std::vector<int>& v, int& shift_by){
  std::vector<int> rotate_vec(v);
  std::rotate(rotate_vec.rbegin(), rotate_vec.rbegin()+shift_by, rotate_vec.rend());
  //std::reverse(rotate_vec.begin(), rotate_vec.end());

  return rotate_vec;
}

std::vector<int> left_rotation(std::vector<int>& v, int& shift_by){
  std::vector<int> rotate_vec(v);
  std::rotate(rotate_vec.begin(), rotate_vec.begin()+shift_by, rotate_vec.end());
  //std::reverse(rotate_vec.begin(), rotate_vec.end());

  return rotate_vec;
}


int StringToNumber(std::string& Text){
     istringstream ss(Text);
     int result;
     ss >> result;
     return result;
}

mp_type StringToNumber_Large(std::string& a){
  mp_type large_number_string(a);
  return large_number_string;
}

std::string LargeNumber_String(mp_type& a){
  std::string num_string = boost::lexical_cast<std::string>(a);
  return num_string;
}


int LargeNumber_Small(mp_type& a){
  int small_int = boost::lexical_cast<int>(a);
  return small_int;
}

std::string NumberToString(int Number){
  ostringstream ss;
  ss << Number;

  std::string out_temp = ss.str();
  //std::cout << out_temp << '\n';
  return out_temp;
}

void print_vector_int(std::vector<int>& v, int& vector_len){
  for(int i = vector_len - 1;i >= 0; i--) 
      std::cout << v[i] << ' ';
    std::cout << '\n';
}

void print_vector_int_string(std::vector<std::string>& v, int& vector_len){
  for(int i = vector_len - 1;i >= 0; i--) 
      std::cout << v[i] << ' ';
    std::cout << '\n';
}

void print_vector_string(std::vector<std::string>& v, int& vector_len){
  for(int i = vector_len - 1;i >= 0; i--) 
      std::cout << v[i] << '\n';
}

std::string return_char_buffer(char*& v, int& vector_len){
  ostringstream temp_numb_buff;
  for(int i = 0;i < vector_len; i++) 
      temp_numb_buff << v[i];

  std::string out_temp_numb_buff = temp_numb_buff.str();
  //std::cout << out_temp_numb_buff << '\n';
  return out_temp_numb_buff;
}

std::string addition(std::string& a, std::string& b){
  mp_type n1(a);
  mp_type n2(b);
  mp_type n3 = n1+n2;

  std::string addition_string = n3.str();//boost::lexical_cast<std::string>(n3);
  return addition_string;
}

std::string subtraction(std::string& a, std::string& b){
  boost::multiprecision::cpp_int n1(a);
  boost::multiprecision::cpp_int n2(b);
  boost::multiprecision::cpp_int n3 = n1-n2;

  std::string subtraction_string = boost::lexical_cast<std::string>(n3);
  return subtraction_string;
}

 std::string multiply(std::string& a, std::string& b){
  boost::multiprecision::cpp_int n1(a);
  boost::multiprecision::cpp_int n2(b);
  boost::multiprecision::cpp_int n3 = n1*n2;

  std::string multiply_string = boost::lexical_cast<std::string>(n3);
  return multiply_string;
}

mp_type divide(std::string& a, std::string& b){
  boost::multiprecision::cpp_int n1(a);
  boost::multiprecision::cpp_int n2(b);

  mp_type n1_float(n1); //= n1.convert_to<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<0> > >();
  mp_type n2_float(n2); //= n2.convert_to<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<0> > >();
  mp_type n3_float = n1_float/n2_float;

  return n3_float;
}

std::string divide_int(std::string& a, std::string& b){
  boost::multiprecision::cpp_int n1(a);
  boost::multiprecision::cpp_int n2(b);

  boost::multiprecision::cpp_int n3 = n1/n2;
  std::string n3_string = boost::lexical_cast<std::string>(n3);

  return n3_string;
}

std::string floor(mp_type& a){
  mp_type n1(a);
  std::string n2 = n1.str();//0, std::ios_base::scientific); //.backend().extract_integer_part();
  //std::string n2 = n1.backend().extract_integer_part();//eval_floor(n1);//boost::math::floor(n1);
  std::vector<std::string> strs;
  boost::split(strs,n2,boost::is_any_of("."));
  //std::cout << strs[0] << std::endl;
  //boost::multiprecision::cpp_int n3(n2[0]);

  std::string floor_string = strs[0];//boost::lexical_cast<std::string>(n3);
  return floor_string;
}

int mod(std::string& a, std::string& b){
  boost::multiprecision::cpp_int n1(a);
  boost::multiprecision::cpp_int n2(b);
  boost::multiprecision::cpp_int n3 = n1 % n2;

  int mod_int = boost::lexical_cast<int>(n3);
  return mod_int;
}


template<class BidirIt>
bool next_permutations(BidirIt first, BidirIt last){
  
  if (first == last) return false;
  BidirIt i = last;
  if (first == --i) return false;

  while (1) {
    int counter = 0;
    BidirIt i1, i2;
    i1 = i;
    if (*--i < *i1) {
      i2 = last;
      while (!(*i < *--i2));
      std::iter_swap(i, i2);
      std::reverse(i1, last);
      counter++;
      std::cout << "counter inc: " << counter << '\n';
      return true;
    }
    if (i == first) {
      std::reverse(first, last);
      std::cout << "counter end: " << counter << '\n';
      return false;
    }
  }
}

void generate_permutations(int& vector_len){
  int number_of_elements = vector_len;
  int default_value = 0;
  std::vector<int> vec(number_of_elements, default_value);

  print_vector_int(vec, vector_len);
  std::cout << '\n' << std::endl;

    for(int i =0; i< number_of_elements; i++){
      int rem_i = (number_of_elements-i-1);
      int ones_i = (i + 1);
      std::vector<int> unique_comb_vect;

      //initalize unique vectors
      std::vector<int> ones_vec(ones_i, 1);
      std::vector<int> zeros_vec(rem_i, default_value);

      //allocate space 
      unique_comb_vect.reserve(ones_vec.size() + zeros_vec.size());

      //add unique vectors to comb vector
      unique_comb_vect.insert(unique_comb_vect.end(), zeros_vec.begin(), zeros_vec.end());
      unique_comb_vect.insert(unique_comb_vect.end(), ones_vec.begin(), ones_vec.end());

      do {
        print_vector_int(unique_comb_vect, vector_len);
      } 
      while ( next_permutations(unique_comb_vect.begin(),unique_comb_vect.end()) );

      std::cout << '\n' << std::endl;
    }
}

//long int compute_factorial(long int number){
void compute_factorial_numbers(int& vector_len){
  int k = 1;
  
  std::string init_string = "1";
  std::vector<std::string> factorials(vector_len,init_string);

  while(k++ < vector_len-1){
    std::string prev_fac = factorials[k-1];
    std::string temp_iter = NumberToString(k);
    factorials[k] = multiply(prev_fac,temp_iter);
  }
  print_vector_string(factorials, vector_len);
}

std::string compute_factorial(std::string& number){
  int start_numb = StringToNumber(number);
  //std::cout << "start_numb: " << start_numb << std::endl;
  //if( number.length() == 1 && ((number[0]-48) <= 1))
  if(start_numb <= 1)
    return number;
  else{
    int start_i = 1;
    std::string out_number = NumberToString(start_i);
    //long int out_number = 1;
    for(int i=1;i<=start_numb;i++){
      //out_number = out_number*i;
      std::string i_n = NumberToString(i);
      std::string temp_out_numb = out_number;
      
      //std::cout << "compute_factorial middle x: " << temp_out_numb << std::endl;

      std::string temp_mult = multiply(temp_out_numb, i_n);
      //temp_mult.erase(0, temp_mult.find_first_not_of('0'));
      out_number.replace(0,out_number.length(), temp_mult);
      
    }
    std::string out_factorial = out_number;
    return out_factorial;
  }
}

std::vector<int> ith_permutation(int& vector_len, std::string index){
  int k = 1;
  int states_vals[2] = {0,1};
  std::string states = "2";
  std::string init_string = "1";
  std::vector<std::string> factorials(vector_len,init_string);
  std::vector<int> ith_permutation_vector(vector_len,0);

  for(int i=0; i<vector_len; i++){
    int item_index = mod(index, states);
    //std::cout << "item_index: " << item_index << std::endl;

    mp_type temp_division = divide(index, states);
    //std::cout << "mp_type: " << temp_division << std::endl;
    index = floor(temp_division);

    ith_permutation_vector[i] = states_vals[item_index];
  }
  std::reverse(ith_permutation_vector.begin(), ith_permutation_vector.end());

  return ith_permutation_vector;
  
}

std::string permutation_to_ith(std::vector<std::string>& v, int& states, int&vector_len){
  std::reverse(v.begin(), v.end());
  std::string k = "0";
  std::string states_string = NumberToString(states);
  std::vector<std::string> states_vector(vector_len,states_string);
  for(int i=0;i<vector_len; i++){
    std::string temp_radix_mult = multiply(k, states_vector[i]);
    std::string temp_digit = v[i];
    k = addition(temp_radix_mult, temp_digit);
  }

  return k;
}

std::string permutation_to_ith(std::vector<int>& v, int& states, int&vector_len){
  std::reverse(v.begin(), v.end());
  std::string k = "0";
  std::string states_string = NumberToString(states);
  std::vector<std::string> states_vector(vector_len,states_string);
  for(int i=0;i<vector_len; i++){
    std::string temp_radix_mult = multiply(k, states_vector[i]);
    std::string temp_digit = NumberToString(v[i]);
    k = addition(temp_radix_mult, temp_digit);
  }

  return k;
}



std::string get_max_swap_offset(std::string& vector_len, std::string& ones_len, int& vector_len_int, int& ones_len_int){
  //if(vector_len <=1)
  //  return vector_len;
  if( vector_len.length() == 1 && ((vector_len[0]-'0') <= 1))
    return vector_len;
  else if(vector_len_int == ones_len_int)
    return "1";
  else if(ones_len_int == 0)
    return "1";
  else if(ones_len == "0")
    return "1";

  std::string fact_n = compute_factorial(vector_len);
  //std::cout << "compute_factorial n: "<< fact_n << '\n';
  std::string fact_k = compute_factorial(ones_len);
  //std::cout << "compute_factorial k: "<< fact_k<< '\n';
  int n_k_int = vector_len_int-ones_len_int;
  std::string n_k = NumberToString(n_k_int);
  std::string fact_n_k = compute_factorial(n_k);
  //std::cout << "compute_factorial (n-k)!: "<< fact_n_k << '\n';

  
  std::string denom_ = multiply(fact_k, fact_n_k);

  boost::multiprecision::cpp_int nom(fact_n);
  boost::multiprecision::cpp_int denom(denom_);
  boost::multiprecision::cpp_int max_x = nom/denom;

  std::string max_x_string = boost::lexical_cast<std::string>(max_x);

  //std::cout << "max x: " << max_x_string << std::endl;
  return max_x_string;
}

std::string next_ith_permutation(std::string permutation_val, std::vector<int> permutation_vector, int vector_len, int next_ith){
  std::cout << "permutation_val: "<< permutation_val << std::endl;
  std::reverse(permutation_vector.begin(), permutation_vector.end());
  int power = 2;
  int one_index = 0;
  int zero_index = 0;
  int subset = 0;

  for(int i = vector_len-1; i>=0; i--){
    if (permutation_vector[i] == 1){
      one_index = i;
      break;
    }
  }

  for(int i = 0; i<vector_len; i++){
    if (permutation_vector[i] == 0){
      zero_index = i;
      break;
    }
  }

  for(int i = 0; i<one_index; i++){
    if(permutation_vector[i] == 0)
      subset++;
  }
  std::cout << "subset: "<< subset << std::endl;

  int one_index_max = one_index+1;
  int subset_offset = subset-1;
  int hamming_dist = 0;
  std::vector<int> hamming_vec(subset,0);
  for(int i = 0; i<subset; i++){
    if(permutation_vector[i] != hamming_vec[i])
      hamming_dist++;
  }
  std::cout << "hamming_dist: "<< hamming_dist << std::endl;

  boost::multiprecision::cpp_int power_cpp_int(2);
  boost::multiprecision::cpp_int one_index_cpp_int(one_index);
  boost::multiprecision::cpp_int one_index_max_cpp_int(one_index_max);
  boost::multiprecision::cpp_int subset_cpp_int(subset);
  boost::multiprecision::cpp_int y0_cpp_int = power_of(power_cpp_int, one_index_cpp_int);// - power_of(power_cpp_int, subset_cpp_int);
  boost::multiprecision::cpp_int yx_i_max_cpp_int = power_of(power_cpp_int, one_index_max_cpp_int) - power_of(power_cpp_int, subset_cpp_int);
  std::string yx_i_max = boost::lexical_cast<std::string>(yx_i_max_cpp_int);
  std::cout << "y0: "<< y0_cpp_int << std::endl;

  int sum_of_elems = std::accumulate(permutation_vector.begin(),permutation_vector.end(),0);
  std::string sum_of_elems_string = NumberToString(sum_of_elems);
  std::string degrees_of_freedom = NumberToString(subset);
  std::string max_sub_permutations = get_max_swap_offset(sum_of_elems_string, degrees_of_freedom, sum_of_elems, subset);

  std::string degrees_of_freedom_offset = NumberToString(subset_offset);
  std::string max_sub_permutations_offset = get_max_swap_offset(sum_of_elems_string, degrees_of_freedom_offset, sum_of_elems, subset);

  int x0;
  int offset_factor = 0;
  int max_start = StringToNumber(max_sub_permutations_offset);
  if(subset != 0)
    offset_factor = subset_offset*max_start;

  //if(hamming_dist == 0)
  //  x0 = 0;
  //else
  x0 = one_index-zero_index+1-offset_factor;

  std::cout << "x0: "<< x0 << std::endl;

  //might need to be an unsigned long
  int x0_i = x0 + next_ith-offset_factor;

  std::cout << "x0_i: "<< x0_i << std::endl;
  boost::multiprecision::cpp_int x0_cpp_int(x0);
  std::string subset_sum_val = "0";
  std::string subset_sum_init_val = "0";
  mp_type subset_sum_val_mp_type("0");
  


  std::string yx_i = "0";

  
  
  //might need to be an unsigned long
  int delta_x;
  int max_delta = StringToNumber(max_sub_permutations);
  delta_x = x0_i-x0;
  int rotate_next_ith = delta_x- max_delta;



  std::string delta_x_string = NumberToString(delta_x);

  boost::multiprecision::cpp_int delta_x_cpp_int(delta_x_string);
  boost::multiprecision::cpp_int max_sub_permutations_cpp_int(max_sub_permutations);
  
  std::cout << "delta_x: " <<delta_x << std::endl;
  std::cout << "max_sub_permutations: " <<max_sub_permutations << std::endl;

  if(delta_x_cpp_int < max_sub_permutations_cpp_int){
    //std::cout << "max not reached: " <<delta_x_cpp_int << std::endl;
    for(int i=x0;i<x0_i;i++){
      boost::multiprecision::cpp_int temp_exp_val_cpp_int(i);
      boost::multiprecision::cpp_int temp_power_val_cpp_int = power_of(power_cpp_int, temp_exp_val_cpp_int);
      std::string y0_cpp_int_string = boost::lexical_cast<std::string>(y0_cpp_int);
      std::string temp_power_val_cpp_int_string = boost::lexical_cast<std::string>(temp_power_val_cpp_int);
      //std::cout << "y0_cpp_int_string: "<< y0_cpp_int_string << std::endl;
      //std::cout << "temp_power_val_cpp_int_string: "<< temp_power_val_cpp_int_string << std::endl;
      mp_type node = divide(y0_cpp_int_string, temp_power_val_cpp_int_string);
      std::string node_str_from_division = divide_int(y0_cpp_int_string, temp_power_val_cpp_int_string);//node.str();
      //std::cout << "node_str_from_division: "<< node_str_from_division << std::endl;
      //std::cout << "divisor: "<< temp_power_val_cpp_int_string << std::endl;
      subset_sum_val = addition(subset_sum_val, node_str_from_division);
      //std::cout << "subset_sum_val: " << subset_sum_val << std::endl;
      std::string temp_yx_i = addition(permutation_val, subset_sum_val);
    }

    yx_i = addition(permutation_val, subset_sum_val);
  }
  else{
    std::cout << "rotate_next_ith: " <<rotate_next_ith << std::endl;
    std::cout << "yx_i_max: " <<yx_i_max << std::endl;
    //will need to rotate vector by one
    int shift_by = 1;
    std::cout << "Warning, next permutations is at max range for this block" << "" << std::endl;
    std::vector<int> temp_perm_vec = ith_permutation(vector_len,yx_i_max);
    std::reverse(temp_perm_vec.begin(), temp_perm_vec.end());
    std::vector<int> rotated_vector = right_rotation(temp_perm_vec, shift_by);
    std::string rotated_ith_perm_val = permutation_to_ith(rotated_vector, power, vector_len);
    //std::cout << "Warning, next permutations is at max range for this block" << " rotating to continue and using recursion" << std::endl;
    //std::cout << "rotate_next_ith: " <<rotate_next_ith << std::endl;
    yx_i = next_ith_permutation(rotated_ith_perm_val, rotated_vector, vector_len, rotate_next_ith);
    
    //print_vector_int(rotated_vector, vector_len);
    //yx_i = "0";
  }
  
  return yx_i;
}


void compute_permutations(int& vector_len, int& ones_len, std::string& swap_offset){

  int rem = (vector_len-ones_len);
  std::vector<int> unique_comb_vect;

  //initalize unique vectors
  std::vector<int> ones_vec(vector_len, 1);
  std::vector<int> zeros_vec(rem, 0);

  //allocate space 
  unique_comb_vect.reserve(ones_vec.size() + zeros_vec.size());

  //add unique vectors to comb vector
  unique_comb_vect.insert(unique_comb_vect.end(), zeros_vec.begin(), zeros_vec.end());
  unique_comb_vect.insert(unique_comb_vect.end(), ones_vec.begin(), ones_vec.end());

  print_vector_int(unique_comb_vect, vector_len);

}

int main(int argc, char *argv[]) {
  //long int vector_len = 128;
  
  int vector_len_int = strtol(argv[1], NULL, 0);
  ostringstream vector_len;
  vector_len << vector_len_int;

  //long int ones_len = 20;
  
  int ones_len_int = strtol(argv[2], NULL, 0);
  ostringstream ones_len;
  ones_len << ones_len_int;

  //generate_permutations(vector_len);
  std::string len_ = vector_len.str();
  std::string ones_ = ones_len.str();

  std::string max = get_max_swap_offset(len_, ones_, vector_len_int, ones_len_int);
  std::cout << "max combinations: "<< max << std::endl;

  //compute_permutations(vector_len_int, ones_len_int, max);
  //compute_factorial_numbers(vector_len_int);

  std::string ith_perm(argv[3]);
  int next_ith = strtol(argv[4], NULL, 0);
  std::vector<std::string> ith_perm_strs;
  boost::split(ith_perm_strs,ith_perm,boost::is_any_of(" "));
  //std::cout << "permutation_val by ith_perm: "<< ith_perm << std::endl;
  //std::vector<int> ith_perm_vec = ith_permutation(vector_len_int,ith_perm);
  
  //./generate_permutations 128 32 "0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0" 0
  int states = 2;
  std::string ith_perm_val = permutation_to_ith(ith_perm_strs, states, vector_len_int);
  std::cout << "ith_perm_val: "<< ith_perm_val << std::endl;

  //int sum_of_elems = std::accumulate(ith_perm_vec.begin(),ith_perm_vec.end(),0);
  //std::cout << "sum of ith_perm_vec: "<< sum_of_elems << std::endl;
  //std::vector<int> ith_perm_vec = ith_permutation(vector_len_int,next_ith_perm_val);
  std::vector<int> ith_perm_vec = ith_permutation(vector_len_int,ith_perm_val);
  int sum_of_elems = std::accumulate(ith_perm_vec.begin(),ith_perm_vec.end(),0);
  std::cout << "sum of ith_perm_vec: "<< sum_of_elems << std::endl;


  //next_permutations(ith_perm_strs.begin(),ith_perm_strs.end());
  //std::reverse(ith_perm_strs.begin(), ith_perm_strs.end());

  //print_vector_int(ith_perm_vec, vector_len_int);
  
  //std::cout << "permutation_val by ith_perm: "<< ith_perm_val << std::endl;
  std::string next_ith_permutation_val = next_ith_permutation(ith_perm_val, ith_perm_vec, vector_len_int, next_ith);
  std::cout << "next " << next_ith << "(st|nd|rd|th) permutation value: "  << next_ith_permutation_val << std::endl;
  std::vector<int> next_ith_perm_vec = ith_permutation(vector_len_int,next_ith_permutation_val);
  int sum_of_next_elems = std::accumulate(next_ith_perm_vec.begin(),next_ith_perm_vec.end(),0);
  std::cout << "sum of next ith_perm_vec: "<< sum_of_next_elems << std::endl;
  print_vector_int(next_ith_perm_vec, vector_len_int);
  
  //std::string ith_plus_1_perm_val = permutation_to_ith(ith_perm_strs, states, vector_len_int);
  //std::cout << "ith_plus_1_perm_val: "<< ith_plus_1_perm_val << std::endl;
  //print_vector_int_string(ith_perm_strs,vector_len_int);

  
  return 0;
}