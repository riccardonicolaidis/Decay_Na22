# Na 22 decay: Geant4 simulation

![Geant4 logo](https://geant4.web.cern.ch/sites/default/files/g4logo-web.png)

This project folder is inspired from the YouTube video series you can find at the following link [Physics Matters](https://www.youtube.com/playlist?list=PLLybgCU6QCGWgzNYOV0SKen9vqg4KXeVL).

- For the official page of **Geant4 toolkit** visit [https://geant4.web.cern.ch/](https://geant4.web.cern.ch/)

------------------------------------

## The content of the software
In this software, a system composed of two NaI scintillators and a Na22 radioactive source is presented.

![detector](/docs/assets/images/detector._0000.png)

The Na 22 is in the middle of the system. The radioactive decay Physics has been introduced in the physics list of the simulation. Using some defined classes, it is possible to measure the energy deposited in the two scintillators due to the radioactivity of the Na 22 source. 

The simulation does not implement the scintillation mechanisms involved in the dectection. The energy spectrum measured in this simulation, will have very narrow photopeaks. 

![A](/docs/assets/images/Edep_A.png)

![B](/docs/assets/images/Edep_B.png)

The effect of the finite resolution can be added later using a convolution with a gaussian noise.

![A gaus](/docs/assets/images/Edep_gaus_A.png)

![B](/docs/assets/images/Edep_gaus_B.png)


If we make the histogram 2D of the two channels it is possible to see the correlation between different Compton edges

![2D A e B](/docs/assets/images/AB.png)

If we add some blur to the histogram, in order to have a realistic detection, the result is the following:

![2D A e B gaus](/docs/assets/images/AB_gaus.png)





## Brief description of the directory structure

This is a **CMake** project. Therefore, a CMake file is required. In this case, the file is named **CMakeLists.txt**. The subdirectory **build/** is needed to compile the project.

The project also contains a method for saving data in root files. The instructions for Geant to store data are contained in the **run.cc** file.

---------------------------------------


## Build the project
To build the project go to the /build directory and run the command

```
cmake ..
```

Then, you can run the command

```
make
```

Then, an executable file will be created in the /build directory. To run the executable file, simply run the command
```
./Name_of_the_executable_file
```
The name of the executable file, in this case, is simply "simulation", which is exactly the name of the project.

--------------------------------------------

## Useful resources 
- Physics Matters Geant4 tutorial : [Link](https://www.youtube.com/playlist?list=PLLybgCU6QCGWgzNYOV0SKen9vqg4KXeVL)
- Geant4 page : [Link](https://geant4.web.cern.ch/)
- Geant4 User guide : [Link](https://geant4.web.cern.ch/support/user_documentation)
- ROOT Cern C++ : [Link](https://root.cern/)