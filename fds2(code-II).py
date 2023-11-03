#code by prince thakur
print("Assignment-2 (String Operations)") 
sentence = input("Enter sentence: ")
longest = max(sentence.split(), key=len)
print("Longest word is: ", longest)
print("And its length is: ", len(longest))

all_freq = {}
for i in sentence:
    if i in all_freq:
     all_freq[i] += 1
    else:
     all_freq[i] = 1

print("Count of all characters in sentence is : \n "
+ str(all_freq))

text="malayalam"
print("Given text is "+text)
rev=reversed (text)
if list (text)==list(rev):
 print("its a palindrome")
else:
 print("its not a palindrome")

sub_strl =str(input("Enter word: "))
print("index or first appearance of the substring "+sub_strl+" is") 
print(sentence.find(sub_strl))

if(sentence.find(sub_strl)==-1): 
    print("Substring Not Found")
else:
 print("Substring found")

print("Following are the count the frequency of each word in a given string")
def freq(sentence):
 sentence=sentence.split()
 str2 = []
 for i in sentence:
  if i not in  str2:
   str2.append(i)
 for i in range(0, len(str2)):
  print('count of frequency', str2[i], 'is :', sentence.count(str2[i]))
def main():
 freq(sentence)
main() 
