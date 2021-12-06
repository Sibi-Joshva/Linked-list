def search(arr, x):
	for i in range(len(arr)):
		if arr[i] ==x:
			return i
	return -1

arr=[]
n = int(input("Enter the NUmber of Elements in the array"))	
for i in range(n):
	num=int(input("Enter the number to be inserted in the array"))
	arr.append(num)
x=int(input("Enter the number to be searched"))
found=search(arr, x)
if(found == -1):
	print("Elements no found")
else:
	print("Element found at position:", found+1)		