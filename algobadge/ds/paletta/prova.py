def mergeSort(arr, n):
	temp_arr = [0]*n
	return _mergeSort(arr, temp_arr, 0, n-1)

def _mergeSort(arr, temp, left, right):
	inversions = 0

	# We will make a recursive call if and only if
	# we have more than one element
	if left < right:
		mid = (left + right)//2

		inversions += _mergeSort(arr, temp, left, mid)
		inversions += _mergeSort(arr, temp, mid + 1, right)

		inversions += merge(arr, temp, left, mid, right)

	return inversions


def merge(arr, temp, left, mid, right):
	i = left
	j = mid + 1
	k = left
	inversions = 0

	while i <= mid and j <= right:

		if arr[i] <= arr[j]:
			temp[k] = arr[i]
			k += 1
			i += 1
		else:
			temp[k] = arr[j]
			inversions += (mid-i + 1)
			k += 1
			j += 1

	while i <= mid:
		temp[k] = arr[i]
		k += 1
		i += 1

	while j <= right:
		temp[k] = arr[j]
		k += 1
		j += 1

	for loop_var in range(left, right + 1):
		arr[loop_var] = temp[loop_var]

	return inversions


arr = [2, 3, 4, 1, 0, 7, 6, 5, 8, 9]

arr1 = []
arr2 = []
for i in range(len(arr)):
	if i % 2 == 0:
		arr1.append(arr[i])
	else:
		arr2.append(arr[i])

result1 = mergeSort(arr1, len(arr1))
result2 = mergeSort(arr2, len(arr2))

print("Number of inversions is", result1+result2)