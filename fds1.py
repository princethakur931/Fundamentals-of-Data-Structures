# Function for average score of the class
def average(listofmarks):
    total = 0
    count = 0
    for i in range(len(listofmarks)):
        if listofmarks[i] != -999:
            total += listofmarks[i]
            count += 1
    avg = total / count
    print("Total Marks:", total)
    print("Average Marks: {:.2f}".format(avg))

# Function for Highest score in the test for the class
def Maximum(listofmarks):
    Max = listofmarks[0]
    for i in range(1, len(listofmarks)):
        if listofmarks[i] != -999 and listofmarks[i] > Max:
            Max = listofmarks[i]
    return Max

# Function for Lowest score in the test for the class
def Minimum(listofmarks):
    Min = listofmarks[0]
    for i in range(1, len(listofmarks)):
        if listofmarks[i] != -999 and listofmarks[i] < Min:
            Min = listofmarks[i]
    return Min

# Function for counting the number of students absent for the test
def absentcount(listofmarks):
    count = 0
    for i in range(len(listofmarks)):
        if listofmarks[i] == -999:
            count += 1
    return count

# Function for displaying marks with highest frequency
def maxFrequency(listofmarks):
    freq_dict = {}
    for mark in listofmarks:
        if mark != -999:
            freq_dict[mark] = freq_dict.get(mark, 0) + 1
    max_freq_mark = max(freq_dict, key=freq_dict.get)
    return max_freq_mark, freq_dict[max_freq_mark]

# Main function
marks_in_FDS = []
number_of_students = int(input("Enter total number of students: "))
for i in range(number_of_students):
    marks = int(input("Enter marks of student {}: ".format(i + 1)))
    marks_in_FDS.append(marks)

flag = 1
while flag == 1:
    print("\n\n--------------------MENU--------------------\n")
    print("1. Total and Average Marks of the Class")
    print("2. Highest and Lowest Marks in the Class")
    print("3. Number of Students absent for the test")
    print("4. Marks with Highest Frequency")
    print("5. Exit\n")
    ch = int(input("Enter your Choice (from 1 to 5): "))

    if ch == 1:
        average(marks_in_FDS)
    elif ch == 2:
        print("Highest Score in Class:", Maximum(marks_in_FDS))
        print("Lowest Score in Class:", Minimum(marks_in_FDS))
    elif ch == 3:
        print("Number of Students absent in the test:", absentcount(marks_in_FDS))
    elif ch == 4:
        mark, fr = maxFrequency(marks_in_FDS)
        print("Highest frequency is of marks {0} that is {1}".format(mark, fr))
    elif ch == 5:
        flag = 0
        print("Thanks for using this program!")
    else:
        print("!!Wrong Choice!!")

    a = input("Do you want to continue (yes/no): ")
    if a.lower() == "yes":
        flag = 1
    else:
        flag = 0
        print("Thanks for using this program!")
