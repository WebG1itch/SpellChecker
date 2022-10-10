Run the program by entering 'make' into the commandline.

The program will request a word to spellcheck (with the assumption that the first letter is correct)
when the word is entered, it will search it's dictionary for the word.
If the word is found, it will return 'true' and print all other words in it's dictionary that start with the same two letters
If the word is not found, it will try to find resemblance to words in it's dictionary.
If no resemblance is found, it will return 'false' and exit
If some resemblance to a word is found, it will ask the user if the new word is what the user meant
If the user enters 'yes' it will print 'true' then all other words in the dictionary that start with the same two letters.
If the user enters 'no' it will print 'false' and exit.