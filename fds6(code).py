
print("assignment-6(store first year percentage using quick sort)")
def input_percentage():
    perc=[]
    number_of_students=int(input("enter the number of students :"))
    for i in range(number_of_students):
        perc.append(float(input("enter the percentage of student {0} :".format(i+1))))
    return perc

def print_percentage(perc):
    for i in range(len(perc)):
        print(perc[i],sep="\n")
        
def percentage_partition(perc,start,end):
    pivot = perc[start]
    lower_bound=start+1
    upper_bound=end
    
    while True:
        while lower_bound <= upper_bound and perc[lower_bound]<=pivot:
            lower_bound +=1
            
        while lower_bound <=upper_bound and perc[upper_bound]>=pivot:
            upper_bound -=1
            
        if lower_bound<=upper_bound:
            perc[lower_bound],perc[upper_bound]=perc[upper_bound],perc[lower_bound]
            
        else:
            break
        
    perc[start],perc[upper_bound]=perc[upper_bound],perc[start]
    return upper_bound

def quick_sort(perc,start,end):
    if start<end:
        partition =percentage_partition(perc,start,end)
        quick_sort(perc,start,partition-1)
        quick_sort(perc,partition+1,end)
        return perc
    
def display_top_five(perc):
     print("top five percentages are : ")
     start, stop = len(perc)-1, max(len(perc)-6, -1)
     for i in range(start, stop, -1):
        print(perc[i])
        
unsorted_percentage=[]
sorted_percentage=[]
flag=1

# (Your existing code above...)

while flag==1:
    print("\n----------menu-------")
    print("1.accept the percentage of students")
    print("2.display the percentage of students")
    print("3.perform quick sort on the data")
    print("4.exit")
    
    ch = int(input("enter your choice(from 1 to 4): "))
    if ch==1:
        unsorted_percentage = input_percentage()
        
    elif ch==2:
        print_percentage(unsorted_percentage)
        
    elif ch==3:
        print("percentage of students after performing quick sort :")
        sorted_percentage = quick_sort(unsorted_percentage, 0, len(unsorted_percentage)-1)
        print_percentage(sorted_percentage)
        a = input("do you want to display the top 5 percentages of students(yes/no):")
        if a == 'yes':
            display_top_five(sorted_percentage)
            
    elif ch==4:  # This is not nested anymore
        print("thanks for using this program!!")
        flag=0
        
    else:
        print("invalid choice!!")
