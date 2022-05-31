import hashlib
import time
s=input("Enter a string ")
start = time.time()
i=0
a=0x00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
while(1):
  s1 = s + str(i)
  result = hashlib.sha256(s1.encode())
  if(int(result.hexdigest(),16)<a):
    break
  i=i+1
print(i)
end = time.time()
print("The time of execution of above program is :", end-start)


