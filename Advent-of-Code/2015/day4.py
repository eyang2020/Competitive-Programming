import hashlib

s = "yzbqklnj"

# part 1
for i in range(10000, 1000000):
    temp = s + str(i);
    res = hashlib.md5(temp.encode())
    res = res.hexdigest()
    if res[0:5] == "00000":
        print(i)
        break
    #print(res.hexdigest())

# part 2
for i in range(10000, 10000000):
    temp = s + str(i);
    res = hashlib.md5(temp.encode())
    res = res.hexdigest()
    if res[0:6] == "000000":
        print(i)
        break
    #print(res.hexdigest())
