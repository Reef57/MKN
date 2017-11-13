import sys
import os

def usage():
	print("\n\n")
	print("python3 MTF.py [MODE] [FILE]\n")
	print("MODES:\n")
	print("\tencode - performs MTF transform\n")
	print("\tdecode - reverses MTF transform\n")

def readFile(filename):

	first = True
	comp = []
	dictionary = []
	with open(filename) as f:
		while True:
			c = f.read(1)

			#EOF
			if not c:
				break
			if c == ' ':
				first = False
			if first:
				if c.isdigit():
					comp.append(int(c))
			if not first:
				if c.isalpha():
					dictionary.append(c)

	return comp, dictionary

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

	return [mod_data,dictionary]

def dMTF(comp, dictionary):
    compressedtext = comp
    dictionary = list(dictionary)

    plaintext = ""
    rank = 0
    for i in compressedtext:
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

		if mode == "encode":
			with open(file, 'r') as f:
				data = f.read()
			newdata = MTF(data)
			newfile = sys.argv[2] + ".mtf"
			with open(newfile, 'w') as f:
				for i in newdata:
					for j in i:
						f.write(str(j))
					f.write(" ")

		elif mode == "decode":
			comp,dictionary = readFile(sys.argv[2])
			newdata = dMTF(comp, dictionary)
			newfile = sys.argv[2].replace(".mtf", "")
			with open(newfile, 'w') as f:
				f.write(newdata)

if __name__ == "__main__":
	main()