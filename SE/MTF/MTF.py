#TODO: fix dMTF
import sys
import os

def usage():
	print("\n\n")
	print("python3 MTF.py [MODE] [FILE]\n")
	print("MODES:\n")
	print("\tencode - performs MTF transform\n")
	print("\tdecode - reverses MTF transform\n")

def MTF(data):
	dictionary = sorted(list(set(data)))
	mod_data = list()
	rank = 0

	for c in data:
		rank = dictionary.index(str(c))
		mod_data += [str(rank)]
		dictionary.pop(rank)
		dictionary.insert(0, c)

	dictionary.sort()

	#print(dictionary)

	return [mod_data,dictionary]

def dMTF(compresseddata):
    compressedtext = compresseddata[0]
    dictionary = list(compresseddata[1])

    plaintext = ""
    rank = 0
    for i in compressedtext:
    	print(i)
    	print("\n")
    	rank = int(i)
    	plaintext = plaintext + str(dictionary[rank])

    	e = dictionary[int(i)]
    	dictionary.pop(int(i))
    	dictionary.insert(0, e)

    return plaintext

def main():
	if len(sys.argv) < 3:
		usage()
	else:
		mode = sys.argv[1]
		file = sys.argv[2]

		with open(file, 'r') as f:
			data = f.read()

		if mode == "encode":
			newdata = MTF(data)
			newfile = sys.argv[2] + ".mtf"
			with open(newfile, 'w') as f:
				f.write(str(newdata))

		elif mode == "decode":
			newdata = dMTF(data)
			newfile = sys.argv[2].replace(".mtf", "")
			with open(newfile, 'w') as f:
				f.write(newdata)

if __name__ == "__main__":
	main()