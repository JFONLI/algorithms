### Programming Assignment #1
# Magical Elements

## Problem Description
There are ๐ elements in the fantasy world: earth, water, air, fire, steel, gold, etc.

The composition of any object can be broken down into a mixture of elements.

    For example, a Dragon Sword consists of 10 kg of steel and 20 kg of gold, while a
    King Slime is composed of 30 kg of water and 40 kg of gold.

    An object's energy is calculated by summing up the mass of its containing element.
    
    For instance, a Dragon Sword has 10 + 20 = 30 units of energy; a King Slime has
    30 + 40 = 70 units of energy.

When two objects are combined, a new object is formed. The formed object contains
both object's elements:

    โข If an element is only obtained from one object, its resulting mass equals the
    mass of the source.

    โข However, if an element exists in both source objects, the resulting mass is the
    greater of the two masses of that element.


Let's say a Dragon Sword and a King Slime are combined, forming Excalibur. (a
legendary sword) The Excalibur consists of 10 kg of steel, 30 kg of water and 40
kg of gold.

You are a State Alchemist. There are ๐ objects in your laboratory, and you know the
composition of each object. You must find the maximum possible energy when
combining ๐พ objects among the ๐ objects.

The process should be performed as fast as possible, since the deadline of your annual
assessment report is around the corner.

## I/O Format
Use standard I/O. (stdin, stdout)
### <b>Input</b>

The 1st line contains one integer ๐ (1 โค ๐ โค 10), representing the number of test
cases ๐. Then ๐ test cases follow.

For the first line of each test case, there are 3 positive integers ๐,๐พ, ๐, as described in
the problem.

Then there are ๐ lines, the ๐
๐กโ
line have ๐ numbers ๐ด๐,1, ๐ด๐,2, โฆ , ๐ด๐,๐
.
๐ด๐,๐
represents the mass of the ๐
๐กโ
element in the ๐
๐กโ object. 0 โค ๐ด๐,๐ < 106
for all
test cases.

## <b>Output</b>
For each test case ๐, output the maximum possible energy and a new line after it.


#### <b>Examples</b>
Input 1<br>
1<br>
3 2 2<br>
3 4<br>
4 3<br>
1 5<br>

Output 1<br>
9<br>

Input 2<br>
1<br>
2 2 3<br>
10 20 0<br>
0 40 30<br>

Output 2<br>
80<br>

