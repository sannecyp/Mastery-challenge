# Revision 10: This revision now does not ignore punctuation when sorting (new change to the specs)
# This revision also alphabetizes the words in each word pair before alphabezing all the pairs 

# This file is written by Prathik Sannecy
# Date Created: 9/23/16

# This program create the kwic function. This function implement Key Word in Context.
# First, it takes a string. Then, it breaks it up by newlines. Each resulting string
# is stored and the Key Word in Context is implemented on each of them.
# It shifts the words in each string, and then sorts the shifts into a list alphabetically.

# Input: String, words to ignore (leading word in the shift), whether to use list pairs
# (keeps track of words that appear multiple times in different lines, and whether to break 
# by newline or by "[lower case character]. "
# Output: List of shifted string+list of multiple pairs (if option is selected)


from multiprocessing import Pool
import time
def shifts(line):
	shift_words_send=[]
	for word in range(0,len(split_words[line])):	
		# for each word of a line, append a "shift" that includes 
		# that word+following words+previous words (in that order).
		# Each shift is a tuple that keeps track of what line the initial word is in
		shift_words_send.append((split_words[line][word:]+split_words[line][0:word],line))
	return shift_words_send

	
def index(line):
	indexed_strings=[]
	print new_shift[0],"\n"
	indexed_strings.append(new_shift[line])
	return indexed_strings
	
split_lines=""
def replace(char):
	global split_lines
	split_lines=split_lines.replace("%s. "%char,"%s. hidden76584Cannotfind"%char)
	
def kwic(total_string, ignoreWords=[],listPairs=False,periodsToBreaks=False):
	global new_shift
	new_shift=[]
	global split_lines
	import string
	import re
	# If periodsToBreak option is selected
	if periodsToBreaks==True:
		# Create a list of lower case letters
		lower_case_letters=list(string.ascii_lowercase)
		split_lines=str(total_string)
		
		for letter in lower_case_letters:
			total_string=total_string.replace("%s. "%letter,"%s. hidden76584Cannotfind"%letter)
		# split on the inserted "hidden76584Cannotfind"
		total_string=total_string.split('hidden76584Cannotfind')
		split_lines=total_string
	
	# Split on newlines if periodsToBreak option is not selected 
	else:
		split_lines=total_string.splitlines()
	
	global split_words
	split_words=[]
	global shift_words
	shift_words=[]
	

	# one list/"set of shifts" for each line
	for line in range(0,len(split_lines)):  
		# contains all the words for each set
		split_words.append([])
		# contains all the "shifts" for each set
		shift_words.append([]) 
	i=0
	for line in range(0,len(split_words)):
		# split each line to see each word seperately
		split_words[line].append(split_lines[i].split()) 
		i+=1
	
	

	# due to the initial empty lists appended to split words, 
	# they are unnecessary outer layers and must be removed
	split_words=[i[0] for i in split_words]	
	
	
	p = Pool(3)
	# go through for each line/"set of shifts"
	# for line in range(0,len(shift_words)):
		# each word in a line corresponds to a shifted version
		# for word in range(0,len(split_words[line])):
			# for each word of a line, append a "shift" that includes 
			# that word+following words+previous words (in that order).
			# Each shift is a tuple that keeps track of what line the initial word is in
			# shift_words[line].append((split_words[line][word:]+split_words[line][0:word],line)) 

	
	new_shift_words=[]
	# Parallelize the process
	shift_words=(p.map(shifts,range(0,len(shift_words))))
	# p.close()
	# p.join()
	# shift_words=new_shift_words[0]
	# f=open('res1','w')
	# f.write(str(new_shift_words))
	# f.close
	
	# now that I am keeping track of what line each shift is in using the tuple,
	# there is no need to have two list to separate each set of shifts
	indexed_strings=[]
	new_index=[]
	# print len(shift_words)

	# new_shift=[]
	# new_shift=shift_words
	# print len(new_shift)
	# new_index.append(p.map(index,range(0,len(new_shift))))
	# p.close()
	# p.join()
	# indexed_strings=new_index
	
	# f=open('res1','w')
	# f.write(str(indexed_strings))
	# f.close

	
	for line in range(0,len(shift_words)):
		# place each tuple keeping track of the index of the shifted version in a new list
		for word in range(0,len(shift_words[line])):	
			indexed_strings.append(shift_words[line][word])
		
	
	# Alphabetize by first element-last element in the list of words in each shifted version in the tuple containing them
	indexed_strings.sort(key=lambda tup: tuple(tup[0][x].lower() for x in range(0, len(tup[0]))))
	
	# take into account lower case should also be considered. For each
	# word to be ignored, remove the capitalization
	ignoreWords=[ ignoreWords[x].lower() for x in range(0,len(ignoreWords))]
	
	# Remove words that should be ignored
	# How it works:
		# for each item in the indexed+sorted list of tuples called "index":
			# Check if the first word in the shifted string(1st element inside the tuple) minus the punctuation
			# is in the list of words to be ignored.
			# If it isn't in the "ignoreWords" add the tuple to the new list called "ignored"
	ignored=[]
	ignored=[indexed_strings[tuple_num] for tuple_num in range(0,len(indexed_strings)) if not (indexed_strings[tuple_num][0][0].lower().translate(None,".?,!:") in ignoreWords)]
				
	# If listPairs option selected
	if listPairs==True:
		from collections import Counter
		from itertools import combinations
		
		# Filter the words by removing special characters and capitalization
		filtered_words=[[] for i in split_words]
		i=0
		# First split by line
		for line in range(0,len(split_words)):
			# Then split by word
			for word in range(0,len(split_words[line])):
			# Filter each word, then put it back in the appropriate place
			# Check to make sure that the word is not already in the list (avoid repition of same word in same line)
				if (split_words[i][word].lower().translate(None,".?,!:") not in filtered_words[line]) and (split_words[i][word].lower().translate(None,".?,!:")!=''):
					filtered_words[line].append(split_words[i][word].lower().translate(None,".?,!:")) 
			i+=1
			
			
		# Count how many word pairs there are
		# Create a dictionary to keep track using the counter function
		d  = Counter()
		for sub in filtered_words:
			# if less than two words in a line, skip it
			if len(filtered_words) < 2:
				continue
			sub.sort()
			# if a pair is found, increment the count number in the dictionary
			for comb in combinations(sub,2):
				d[comb] += 1
		
		# Convert to list
		pairs=d.items()
		
		# alphabetize each word pair
		for i in range(0, len(pairs)):
			if pairs[i][1]<2:
				pairs[i]=[]
			else:
				pairs[i]=list(pairs[i])
				pairs[i].sort
				pairs[i]=tuple(pairs[i])
		
		pairs=filter(lambda a: a != [], pairs)	
		
		# Alphabetize by first element-last element in the list of list-pairs
		pairs.sort(key=lambda tup: tuple(tup[0][x].lower().translate(None,".?,!:") for x in range(0, len(tup[0]))))
		alphabetized=pairs[:]
		
		
		
		total=(ignored,alphabetized)
	# If listPairs option is not selected
	else:
		total=ignored
	
	return total

	


with open('chesterton.txt', 'r') as myfile:
    data=myfile.read()

	
begin =time.time()
print kwic(data,listPairs=False)

