# Lab-projects
## Phone Book with C++

### Methods in this project. 

These functions, under the class phone, perform the following operations.
- newrecord()- It allow user to enter new record. 
- display()- It displays all the entries . 
- display(char *nm)- It searches for added record by name. 
- searchpname()- It searches for added record by phone number. 
- updatetelno()- This function is used to modify added records. 
- deleterec()- It deletes record from file.

#### Principles of OOPS implemented in the project-
- Classes and objects
- Namespace
- Header files
- Exception handling
- Function overloading(polymorphism)
- File handling

#### newrecord
newrecord function takes the input from the user as A NAME and A CONTACT NUMBER.getdata function is called in newrecord .

In getdata function we check the validity of the number entered with the help of exception handling.

We will check the  uniqueness of  the contact entered . If the contact is already existing it will show the message.

After a successful addition of the Record another message will appear on the screen .


#### display
We have used function overloading to display records.

One function is designed to display all the records of the contact list.

Other function is designed to display a contact number with a given name.


#### searchpname

With a given telephone number it searches and displays the name of the person holding that phone number.


#### update

Update function has 2 options of updating.
- Updating name of the contact
- Updating conact number.

#### delete
Delete function deletes the record by taking the name of the the person holding the contact number.

If two person have the same name then it will give the option of deleting the record by looking at their contact.
