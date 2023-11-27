def matrix_input(rows, cols):
    matrix = []
    print(f"Enter {rows}x{cols} matrix:")
    for i in range(rows):
        row = list(map(int, input().split()))
        matrix.append(row)
    return matrix

def matrix_addition(mat1, mat2):
    result = [[mat1[i][j] + mat2[i][j] for j in range(len(mat1[0]))] for i in range(len(mat1))]
    return result

def matrix_subtraction(mat1, mat2):
    result = [[mat1[i][j] - mat2[i][j] for j in range(len(mat1[0]))] for i in range(len(mat1))]
    return result

def matrix_multiplication(mat1, mat2):
    result = [[sum(mat1[i][k] * mat2[k][j] for k in range(len(mat2))) for j in range(len(mat2[0]))] for i in range(len(mat1))]
    return result

def matrix_transpose(matrix):
    result = [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]
    return result

def print_matrix(matrix):
    for row in matrix:
        print(" ".join(map(str, row)))

# Take input for the first matrix
rows1, cols1 = map(int, input("Enter rows and columns of the first matrix: ").split())
mat1 = matrix_input(rows1, cols1)

# Take input for the second matrix
rows2, cols2 = map(int, input("Enter rows and columns of the second matrix: ").split())
mat2 = matrix_input(rows2, cols2)

while True:
    print("\nMatrix Operations Menu:")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Transpose")
    print("5. Exit")
    choice = input("Enter your choice (1-5): ")

    if choice == '5':
        print("Thanks for using this program !!")
        break

    if choice == '1':
        if rows1 != rows2 or cols1 != cols2:
            print("Matrix addition not possible. Matrices must have the same dimensions.")
        else:
            result = matrix_addition(mat1, mat2)
            print("\nMatrix Addition Result:")
            print_matrix(result)
    elif choice == '2':
        if rows1 != rows2 or cols1 != cols2:
            print("Matrix subtraction not possible. Matrices must have the same dimensions.")
        else:
            result = matrix_subtraction(mat1, mat2)
            print("\nMatrix Subtraction Result:")
            print_matrix(result)
    elif choice == '3':
        if cols1 != rows2:
            print("Matrix multiplication not possible. Columns of the first matrix must be equal to rows of the second matrix.")
        else:
            result = matrix_multiplication(mat1, mat2)
            print("\nMatrix Multiplication Result:")
            print_matrix(result)
    elif choice == '4':
        transpose_choice = input("Transpose of which matrix? (1 for the first matrix, 2 for the second matrix): ")
        if transpose_choice == '1':
            result = matrix_transpose(mat1)
            print("\nTranspose of the First Matrix:")
            print_matrix(result)
        elif transpose_choice == '2':
            result = matrix_transpose(mat2)
            print("\nTranspose of the Second Matrix:")
            print_matrix(result)
        else:
            print("Invalid choice for transpose. Please enter 1 or 2.")
    else:
        print("Invalid choice. Please enter a number between 1 and 5.")
