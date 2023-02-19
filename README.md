# **push_swap**
This project was graded <strong>84/100</strong>.
- 3 Numbers: OK
- 5 Numbers: OK
- 100 Numbers: 3/5
- 500 Numbers: 4/5

## 📒 **About**
Do you ever worry about efficiency? If you do, this should be a good puzzle for you: in the push_swap project you are challenged to sort a stack A using the least number of available instructions possible. You are allowed to use an auxiliary stack B.

## **Mandatory Part**

The following algorithms were implemented:

- **<= 20** Numbers: `selection sort`
- **\> 20** Numbers: `radix sort`

## 🚨 **Disclaimer**
At 42, the C projects are built following a bunch of rules that enforce good coding style. Some of them are:

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
	- No more than 5 variables in 1 function
	... 

## 🔧 **Implementation**

<table>
	<thead>
		<tr>
			<th>Part</th>
			<th>File Name</th>
			<th>Functionality</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td rowspan = 7><strong>Mandatory</strong></td>
		</tr>
		<tr>
			<td>includes/</td>
			<td>Contains all the necessary .h files</td>
		</tr>
		<tr>
			<td>libft/</td>
			<td>Contains the files from the libft project</td>
		</tr>
		<tr>
			<td>srcs</td>
			<td>Contains the .c files</td>
		</tr>
		<tr>
			<td>checker_linux</td>
			<td>The binary provided by 42 to evaluate the instruction list validness</td>
		</tr>
		<tr>
			<td>main.py</td>
			<td>A python script that I wrote to generate a random numbers list (not submitted). Can be run using <strong>python3 -B main.py</strong> </td>
		</tr>
		<tr>
			<td>main.c</td>
			<td>Where the project is launched from</td>
		</tr>
	</tbody>
</table>


## 📦 **Compilation**
To compile push_swap you should run `make` in the terminal.

This rule will generate a `push_swap` file, which is the zipped version of all the object files. To launch the executable you should follow this syntax...

```sh
$ ./push_swap N1 N2 N3 N4 ...
```

...where each argument is a number you should use as input to display the map. Any misconfiguration such as non numerical, duplicated or int-overflowed numbers should print "Error\n" in the standard error output.

## 💫 **Testing**

This project was tested using mainly the checker and this [push swap visualizer](https://github.com/o-reo/push_swap_visualizer).


## 📞 **Contact me**

Feel free to ask me any questions through Slack (**ncarvalh**).

