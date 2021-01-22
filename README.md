# OpenGL

## Description
* This project uses the GLFW library to implement OpenGL.  GLFW makes creating a window for our scene simple by handling the Windows API for us.
* These instructions assume that you already have Visual Studio downloaded.  If you are unfamiliar with dependencies and linking libraries, then I highly recommend using Visual Studio in order to follow along.*

## Getting Started
### Make sure your GPU drivers are up to date
Outdated drivers could cause issues with OpenGL that might be difficult to troubleshoot

### Clone This Project
1. Go to the main screen of this repository and click the green "Code" button
2. Then click "Open in Visual Studio"
###### If you do not have the option to "Open in Visual Studio", you might not have a source control extension installed to Visual Studio.
###### If this is the case just use one of the other options of cloning and open your project in Visual Studio. Then skip step 3.
3. In Visual Studio Team Explorer should show up and give the option click 'Clone' with a checkbox for 'recursively'.  Make sure that checkbox is checked and click 'Clone'
4. Save the project
5. Open up the project in your file explorer.  You should see the file 'OpenGL.sln' in the current directory
6. Create a folder in this directory called 'Dependencies'
7. Go into the 'Dependencies' folder and create another folder called 'GLFW'

### Downloads
OpenGL is usually already installed by your operating system so all we really need to worry about downloading is GLFW

#### Downloading GLFW
1. Go to https://www.glfw.org/
2. Click Download at the top in the Navigation Bar (not the orange "DOWNLOAD GLFW 3.3.2" button)
3. Click 32-bit Windows binaries to start the download
4. Unzip the folder and open up its location in file explorer

### Directories, Dependencies, and Linking

#### Placing our dependencies and libraries in convenient locations

1. Go into the unzipped GLFW folder and copy both the "include" and the "lib-vc2019" folder (if using Visual Studio 2019, else select your version)
2. Then, while still in your file explorer, navigate back to the OpenGL project.  Go into 'Dependencies' and then into the 'GLFW' folder that we created.
3. Paste the 'include' and 'lib-vc2019' folders that we copied


## You should be done at this point
When you run your program you should see both a terminal and an empty window.
If you would like to create your own project from scratch, follow the above instructions without cloning this project and continue through the following instructions.
Learning to handle paths, dependencies, and libraries will be useful if we decide to add more utility libraries later on.


#### Dependencies

###### Here we tell our project where we placed our 'include' dependencies by giving it a path to follow

1. In Visual Studio look to the Solution Explorer on the side
2. Right-click on the 'OpenGL' folder and go to 'Properties'
3. At the top, change the configuration to 'All Configurations'
4. In the Configuration Properties on the side navigate to 'C/C++' > 'General'
5. Where it says Additional Include Directories, click the drop-down button and then click edit
6. In the top text field add '$(Solution)Dependencies\GLFW\include' then click 'OK'
  This gives our project a path to our 'Dependencies' folder

#### Libraries

###### Here we tell our project where we placed our libraries in the 'lib-vc2019' folder
###### We then tell our project which libraries we would like to link

1. In the Configuration Properties navigate to 'Linker' > 'General'
Where it says Additional Library Directories, click the drop-down button and then click edit
2. In the top text field add '$(Solution)Dependencies\GLFW\lib-vc2019' then click 'OK'
3. In the Configuration Properties navigate to 'Linker' > 'Input'
4. In the top text field add 'glfw3.lib', press 'Return' on your keyboard
5. Then also add 'opengl32.lib', press 'Return' on your keyboard and then click 'OK'

### You're all done!
When you run your program, you should have a command line and an empty window pop up

If you'd like to dig deeper into C++, OpenGL, linking libraries and dependencies, or game engine development then I highly recommed this YouTube channel
https://www.youtube.com/watch?v=W3gAzLwfIP0&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2

