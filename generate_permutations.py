import sys
from itertools import combinations, chain, permutations,product
import random

#binary?

def rotate(l,n):
	return l[n:] + l[:n]

def rotate_and_permute(_list_, _sum_, k):
	seen = dict()
	for i in range(0,k):
		temp_list = _list_

		for z_p in range(0,k):
			if temp_list[i-z_p] == 1:
				temp_list[i-z_p] = 0
				break
				
		if sum(temp_list) == _sum_-1:
			for z in range(0,k):
				if temp_list[-z] == 0:
					temp_list[-z] = 1
					break

			for j in range(0,k):
				temp_rot = rotate(temp_list, j)
				hash_rot = '-'.join([str(x) for x in temp_rot])
				if hash_rot not in seen:
					seen[hash_rot] = 1
					print temp_rot
		
def permutation_vector_to_permutation_matrix(permutation_vector):
	#convert vector to matrix representation
	pass

def shift_permutation_matrix_by_center_of_mass(permutation_matrix):
	#shift permutation matrix to put the center of mass at the orifin
	pass

def birkhoff_polytype_matrix_projection(shifted_permutation_matrix):
	#change of basis to subspace orthogonal to W(1,i) and W(i,1).
	"""
	Let us denote by W(i,1) an n x n matrix with all elements except a single ith row of ones set to zero
	and likewise W(1,i) for columns.
	"""
	pass

def print_matrix_from_random_vector(leads):
	matrix = [0]*128
	total = 0

	index_i = 0
	while total != leads:
		if index_i == 128:
			index_i = 0

		if random.random() > .5:
			matrix[index_i] = 1
			total +=1

		index_i +=1

	for i in range(0,len(matrix)):
		temp_matrix = ['0']*128
		if matrix[i] == 1:
			temp_matrix[i] = '1'
		print ','.join(temp_matrix)


print_matrix_from_random_vector(32)

"""
space = [1]
k = 4
init_list = [0] * k


for i in range(0,k):
	temp = [1] * (i+1) + [0]*(k-i-1)
	_sum_ = sum(temp)
	print 'In: ',i+1, 'sum: ', _sum_, temp
	rotate_and_permute(temp, _sum_, k)
"""