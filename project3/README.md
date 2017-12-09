



Profiling Test Results:
1) Profiling time for memove functions for 1 byte data (Time in micro seconds)

	           10 bytes	 100 bytes	1000 bytes	5000 bytes
lib-memmove	      3	        20	       188	       170
my-memmove	      7	        55	        31	       150
my-memmove-O3	      2	         6	        48	       236
dma-memmove	      8	        12	        50	       216

2) Profiling time for memset functions for 1 byte data (Time in micro seconds)

	           10 bytes	 100 bytes	1000 bytes	5000 bytes
lib-memset	      2	        15	       146	       218
my-memset	      6	        47	       203	       245
my-memset-O3	  2	        15	       147	       218
dma-memset	      8	        12	        49	       216
