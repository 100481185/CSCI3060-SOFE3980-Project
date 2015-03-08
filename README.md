[id1]: <https://magnum.travis-ci.com/ncdesouza/xstream.svg?token=WZRVmSR43sduJMwFxmyr>
[xStream.zip]: <https://github.com/100481185/CSCI3060-SOFE3980-Project/archive/mirror.zip>     
[wdgt]: <https://magnum.travis-ci.com/ncdesouza/XSTREAM>
[@mohammad]: <mohammad.ali3@uoit.net>   
[@nicholas]: <nicholas.desouza@uoit.net>
[@bradley]: <bradley.hamilton@uoit.net>
[@fuad]: <fuad.tareq@uoit.net>  



xStream Project: <br>[![Build Status](https://magnum.travis-ci.com/ncdesouza/XSTREAM.svg?token=WZRVmSR43sduJMwFxmyr)][wdgt]  <sup><sub>CSCI3060/SOFE3980: Software Quality and Assurance</sub></sup>
=================
---
```html 
DevelopmentTeam        
--------------------------------                  
Mohammad Ali      [@mohammad]     
Nicholas De Souza [@nicholas]     
Bradley  Hamilton [@bradley]     
Fuad     Tareq    [@fuad]                       
```
***
===
Installation:           
--------------           
###Get the source:          

There are two options main methods to obtain the source code.  

* Option1: Download the zip:

    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;__[ [xStream.zip][] ]__ 

* Option2: Clone the github repository:
    In terminal type:
     
    ```bash
    sudo git clone https://github.com/100481185/CSCI3060-SOFE3980-Project.git
    ```

###Compiling the source

1. Navigate to xstream directory you just cloned or unzipped, 
   
   using terminal, type the command:

    __`cd /<path>/<to>/xstream`__

2. To make a build directory, type the command:

    __`mkdir build`__
    
3. To navigate into __build__ directory, type the command

    __`cd build`__

4. To run CMake type the command:
    
   __`cmake ..`__
    
5. To run make type the command:
    
    __`sudo make`__ 
    
###Run the program
1. Navigate to the build directory, 

   using terminal, type the command:
  
    __`cd /path/to/xstream/build`__
  
2. To run the program type the command:

    __`./xstream`__

###Run the tests

    OPTIONS:
        1. All
        2. TestSuite
        3. TestCase

#####__OPTION 1: All__

1. Navigate to the test directory,

   using terminal, type the command:

    __`cd /path/to/xstream/test`__
    
2. type
3. 

#####__OPTION 2: All__
```bash
All TestSuites are pre-fixed with the name of the suite. 
For example:
    if NAME of the TestSuite is 'Login',
    then the TestSuite is named:`
        LoginTestSuite
```
1. Navigate to the TestSuite directory,

   using terminal, type the command:

    __`cd /path/to/xstream/test/<Name>TestSuite`__
    
2. To run the TestSuite, type the command

    ```bash
    bash <Name>TestSuite.sh
    ```

3. 


    
###Code Style
This is a reference to code style used in the this project.

__http://google-styleguide.googlecode.com/svn/trunk/cppguide.html__

 
