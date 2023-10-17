import numpy as np
import threading
import time

# Define matrix dimensions
matrix_size = 100
A = np.random.rand(matrix_size, matrix_size)
B = np.random.rand(matrix_size, matrix_size)

# Function to perform matrix multiplication for a single row
def multiply_row(row, A, B, result):
    for j in range(len(B[0])):
        for k in range(len(B)):
            result[row][j] += A[row][k] * B[k][j]

# Function to perform matrix multiplication in a single thread
def single_threaded_matrix_multiplication(A, B):
    result = np.zeros((len(A), len(B[0])))
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                result[i][j] += A[i][k] * B[k][j]
    return result

# Function to perform matrix multiplication with one thread per row
def multithreaded_matrix_multiplication(A, B, num_threads):
    result = np.zeros((len(A), len(B[0])))
    threads = []
    
    for i in range(len(A)):
        thread = threading.Thread(target=multiply_row, args=(i, A, B, result))
        threads.append(thread)
        thread.start()
    
    for thread in threads:
        thread.join()
    
    return result

# Measure execution time for single-threaded multiplication
start_time = time.time()
result_single_threaded = single_threaded_matrix_multiplication(A, B)
single_threaded_execution_time = time.time() - start_time

# Measure execution time for multithreaded multiplication (one thread per row)
start_time = time.time()
num_threads = matrix_size  # One thread per row
result_multithreaded = multithreaded_matrix_multiplication(A, B, num_threads)
multithreaded_execution_time = time.time() - start_time

# Verify the correctness of results by comparing them
assert np.allclose(result_single_threaded, result_multithreaded)

# Print execution times and performance comparison
print(f"Single-threaded execution time: {single_threaded_execution_time:.2f} seconds")
print(f"Multithreaded execution time ({num_threads} threads): {multithreaded_execution_time:.2f} seconds")
