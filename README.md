 This project has been created as part of the 42 curriculum by abchtaib

 DESCRIPTION :
    This project is about implementing a programe that can sort random numbers in ascending order it looks easy in first, but what make this project special is we have just limited operation to move the elemnt inside the stacks for exemple "ra" or "rb" move the first element of the stack "a or b" to the last, we should not exeed the number of moves required , for exemple we have 100 should not pass 700 move as maximum , the algorithme tha i choose called turk, after  receiving i put all the element in the stacka and i check if there is duplicate or invalid input
    if yes i free and stop the programe and display Error, if not which mean i have a valid input i should sort the number now, i start with pushing all the number in the stackb until i have only 3 in stack a i sort those 3 and after it i choose from the stack b the most cheapest move that i can repush to stack a but next to the smallest bigger one, and so on, after that the stacka is not fully sorted, i should find the smalest element and put it at the top, after that the stack a is fully sorted. 

INSTRUCTIONS :
    To compile the program, run make in the project root directory this will generate push_swap executable, to execute the programe run ./push_swap followed by numbers you want to sort.

RESOURCES : 
    Wikipidia, google (sorting algorithms), grok.