main : 1 0 12 2 5 6 11 9 8 3 10 7 4

#1
main : 11	9	12	3	10	7
pend : 1	0 	8	2 	5	6	4
pair : 11-1 9-0 12-3 3-2 10-5 7-6

#2
main : 11	10	12
pend : 3	9	7
pair : 11-3 10-9 12-7

#3
main : 11
pend : 10	12
pair : 11-10

"@@@@@@@@@@@@@@@@@@@@"SORT#3"@@@@@@@@@@@@@@@@@@@@"
main : [0]11
pend : [0]10	[1]12
pair : [0]11-10
makeJacob(pend.size()) : 1, 2
jacob[i] : 0, 1

sorted(main) : [0]11
sorted.insert(sorted.begin(), pend[0]);
sort : [0]10	[1]11
pend : 			[0]10	[1]12

i = 1; // jacobArr index
while (i < jacob.size())
jacob[i] = 1; @@@@ jacob[i](1) + i(1) - 1
Binary(sorted, pend[jacob[i]], rightEnd);  rightEnd : 1 pend[1]"12" -> insert
while end


return sorted;

for (index i = 0; i < main.size())
	//pending - main sort with pair info

"@@@@@@@@@@@@@@@@@@@@"SORT#2"@@@@@@@@@@@@@@@@@@@@"
main : [0]10	[1]11	[2]12
pend : [0]9		[1]3 	[2]7
makeJacob(pend.size()) : 1, 3, 2
jacob[i] : 0, 2, 1

sorted(main) : [0]10	[1]11	[2]12
sorted.insert(sorted.begin(), pend[0]);
sort : [0]9		[1]10	[2]11	[3]12
pend : 			[0]9	[1]3 	[2]7

i = 1; // jacobArr index
while (i < jacob.size())
jacob[i] = 2 @@@@@@@ 2 + i(1) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 2 (sort[3]"12" > pend[2]"7")

sort : [0]7 	[1]9	[2]10	[3]11	[4]12
pend : 					[0]9	[1]3 	[2]7
jacob[i] = 1 @@@@@@@ 1 + i(2) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 2 (sort[3]"11" > pend[1]"3")

sort : [0]3 	[1]7 	[2]9	[3]10	[4]11	[5]12
pend : 							[0]9	[1]3 	[2]7

while end


return sorted;

for (index i = 0; i < main.size())
	//pending - main sort with pair info

"@@@@@@@@@@@@@@@@@@@@"SORT#1"@@@@@@@@@@@@@@@@@@@@"
main : [0]3 	[1]7 	[2]9	[3]10	[4]11	[5]12
pend : [0]2		[1]6	[2]0	[3]5	[4]1	[5]8	[6]4
makeJacob(pend.size()) : 1, 3, 2, 5, 4, 7, 6
jacob[i] : 0, 2, 1, 4, 3, 6, 5

sorted(main) : [0]3 	[1]7 	[2]9	[3]10	[4]11	[5]12
sorted.insert(sorted.begin(), pend[0]);
sort : [0]2 	[1]3 	[2]7 	[3]9	[4]10	[5]11	[6]12
pend : 			[0]2	[1]6	[2]0	[3]5	[4]1	[5]8	[6]4

i = 1; // jacobArr index
while (i < main.size())
jacob[i] = 2; @@@@@@@ 2 + i(1) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 2 (sort[3]"9" > pend[2]"0")

sort : [0]0		[1]2 	[2]3 	[3]7 	[4]9	[5]10	[6]11	[7]12
pend : 					[0]2	[1]6	[2]0	[3]5	[4]1	[5]8	[6]4
jacob[i] = 1; @@@@@@@ 1 + i(2) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 2 (sort[3]"7" > pend[1]"6")

sort : [0]0		[1]2 	[2]3 	[3]6	[4]7 	[5]9	[6]10	[7]11	[8]12
pend : 					[0]2			[1]6	[2]0	[3]5	[4]1	[5]8	[6]4
jacob[i] = 4 @@@@@@@ 4 + i(3) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 6 (sort[7]"11" > pend[4]"1")

sort : [0]0		[1]1	[2]2 	[3]3 	[4]6	[5]7 	[6]9	[7]10	[8]11	[9]12
pend : 							[0]2			[1]6	[2]0	[3]5	[4]1	[5]8	[6]4
jacob[i] = 3 @@@@@@@ 3 + i(4) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 6 (sort[7]"10" > pend[3]"5")

sort : [0]0		[1]1	[2]2 	[3]3 	[4]5	[5]6	[6]7 	[7]9	[8]10	[9]11	[10]12
pend : 							[0]2					[1]6	[2]0	[3]5	[4]1	[5]8	[6]4
jacob[i] = 6 @@@@@@@ 6 + i(5) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 10 (pend[6]"4")

sort : [0]0		[1]1	[2]2 	[3]3 	[4]4	[5]5	[6]6	[7]7 	[8]9	[9]10	[10]11	[11]12
pend : 							[0]2					[1]6			[2]0	[3]5	[4]1	[5]8	[6]4
jacob[i] = 5 @@@@@@@ 5 + i(6) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 10 (sort[11]"12" > sortpend[5]"8")

sort : [0]0		[1]1	[2]2 	[3]3 	[4]4	[5]5	[6]6	[7]7 	[8]8	[9]9	[10]10	[11]11	[12]12
pend : 							[0]2					[1]6					[2]0	[3]5	[4]1	[5]8	[6]4

while end


return sorted










main : [0]0		[1]1	[2]2 	[3]3 	[4]4	[5]5	[6]6	[7]7 	[8]8	[9]9	[10]10	[11]11	[12]12
pend : [0]-3	[1]-11	[2]-5 	[3]1 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4
makeJacob(pend.size()) : 1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 13, 12
jacob[i] : 0, 2, 1, 4, 3, 10, 9, 8, 7, 6, 5, 12, 11

sorted(main) : [0]0		[1]1	[2]2 	[3]3 	[4]4	[5]5	[6]6	[7]7 	[8]8	[9]9	[10]10	[11]11	[12]12
sorted.insert(sorted.begin(), pend[0]);

sort : [0]-3	[1]0	[2]1	[3]2 	[4]3 	[5]4	[6]5	[7]6	[8]7 	[9]8	[10]9	[11]10	[12]11	[13]12
pend : 			[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4

i = 1; // jacobArr index
while (i < jacob.size())
jacob[i] = 2; @@@@@@@ 2 + i(1) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 2 (sort[3]"2" > pend[2]"-5") 3개 -> 2번 비교

sort : [0]-5	[1]-3	[2]0	[3]1	[4]2 	[5]3 	[6]4	[7]5	[8]6	[9]7 	[10]8	[11]9	[12]10	[13]11	[14]12
pend : 					[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4
jacob[i] = 1; @@@@@@ 1 + i(2) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 2 (sort[3]"1" > pend[1]"-11") 3개 -> 2번 비교

"==================================================================================================================================================================================================="
"==================================================================================================================================================================================================="

sort : [0]-11	[1]-5	[2]-3	[3]0	[4]1	[5]2 	[6]3 	[7]4	[8]5	[9]6	[10]7 	[11]8	[12]9	[13]10	[14]11	[15]12
pend : 							[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4
jacob[i] = 4; @@@@@@@ 4 + i(3) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 6 (sort[7]"4" > pend[4]"-6") 7개 -> 3번 비교

sort : [0]-11	[1]-6	[2]-5	[3]-3	[4]0	[5]1	[6]2 	[7]3 	[8]4	[9]5	[10]6	[11]7 	[12]8	[13]9	[14]10	[15]11	[16]12
pend : 									[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4
jacob[i] = 3; @@@@@@@ 3 + i(4) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 6 (sort[7]"3" > pend[3]"-7") -> 3번 비교

"==================================================================================================================================================================================================="
"==================================================================================================================================================================================================="

sort : [0]-11	[1]-7	[2]-6	[3]-5	[4]-3	[5]0	[6]1	[7]2 	[8]3 	[9]4	[10]5	[11]6	[12]7 	[13]8	[14]9	[15]10	[16]11	[17]12
pend : 											[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4
jacob[i] = 10; @@@@@@@ 10 + i(5) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 14 (sort[15]"10" > pend[10]"-12") 15개 -> 4번 비교

sort : [0]-12	[1]-11	[2]-7	[3]-6	[4]-5	[5]-3	[6]0	[7]1	[8]2 	[9]3 	[10]4	[11]5	[12]6	[13]7 	[14]8	[15]9	[16]10	[17]11	[18]12
pend : 													[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4
jacob[i] = 9; @@@@@@@ 9 + i(6) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 14 (sort[15]"9" > pend[9]"-1")

sort : [0]-12	[1]-11	[2]-7	[3]-6	[4]-5	[5]-3	[6]-1	[7]0	[8]1	[9]2 	[10]3 	[11]4	[12]5	[13]6	[14]7 	[15]8	[16]9	[17]10	[18]11	[19]12
pend : 															[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4
jacob[i] = 8; @@@@@@@ 8 + i(7) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 14 (sort[15]"8" > pend[8]"-8")

sort : [0]-12	[1]-11	[2]-8	[3]-7	[4]-6	[5]-5	[6]-3	[7]-1	[8]0	[9]1	[10]2 	[11]3 	[12]4	[13]5	[14]6	[15]7 	[16]8	[17]9	[18]10	[19]11	[20]12
pend : 																	[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4
jacob[i] = 7; @@@@@@@ 7 + i(8) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 14 (sort[15]"7" > pend[7]"-9")

sort : [0]-12	[1]-11	[2]-9	[3]-8	[4]-7	[5]-6	[6]-5	[7]-3	[8]-1	[9]0	[10]1	[11]2 	[12]3 	[13]4	[14]5	[15]6	[16]7 	[17]8	[18]9	[19]10	[20]11	[21]12
pend : 																			[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4
jacob[i] = 6; @@@@@@@ 6 + i(9) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 14 (sort[15]"6" > pend[6]"-10")

sort : [0]-12	[1]-11	[2]-10	[3]-9	[4]-8	[5]-7	[6]-6	[7]-5	[8]-3	[9]-1	[10]0	[11]1	[12]2 	[13]3 	[14]4	[15]5	[16]6	[17]7 	[18]8	[19]9	[20]10	[21]11	[22]12
pend : 																					[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4
jacob[i] = 5; @@@@@@@ 5 + i(10) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 14 (sort[15]"5" > pend[5]"-2")

"==================================================================================================================================================================================================="
"==================================================================================================================================================================================================="

sort : [0]-12	[1]-11	[2]-10	[3]-9	[4]-8	[5]-7	[6]-6	[7]-5	[8]-3	[9]-2	[10]-1	[11]0	[12]1	[13]2 	[14]3 	[15]4	[16]5	[17]6	[18]7 	[19]8	[20]9	[21]10	[22]11	[23]12
pend : 																							[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4
jacob[i] = 12; @@@@@@@ 12 + i(11) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 22 (sort[23]"1" > pend[12]"-4") 23개 -> 5번 비교

sort : [0]-12	[1]-11	[2]-10	[3]-9	[4]-8	[5]-7	[6]-6	[7]-5	[8]-4	[9]-3	[10]-2	[11]-1	[12]0	[13]1	[14]2 	[15]3 	[16]4	[17]5	[18]6	[19]7 	[20]8	[21]9	[22]10	[23]11	[24]12
pend : 																									[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4
jacob[i] = 11; @@@@@@@ 11 + i(12) - 1
Binary(sorted, pend[jacob[i]], rightEnd); rightEnd : 22 (sort[23]"1" > pend[11]"-13")

sort : [0]-13	[1]-12	[2]-11	[3]-10	[4]-9	[5]-8	[6]-7	[7]-6	[8]-5	[9]-4	[10]-3	[11]-2	[12]-1	[13]0	[14]1	[15]2 	[16]3 	[17]4	[18]5	[19]6	[20]7 	[21]8	[22]9	[23]10	[24]11	[25]12
pend : 																											[0]-3	[1]-11	[2]-5 	[3]-7 	[4]-6	[5]-2	[6]-10	[7]-9 	[8]-8	[9]-1	[10]-12	[11]-13	[12]-4






1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
