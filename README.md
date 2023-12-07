# Text Scramble
 
> Authors: [Brandon Vo](https://github.com/bxnvo)
> [Matthew Chun](https://github.com/matthwchun)
> [Randall Nguyen](https://github.com/1rwen)
> [Willa Ralston](https://github.com/chairfu)

## Project Description
This is important because it develops useful skills for coding such as accuracy and speed which is useful for completing tasks quickly. Furthermore, typing is an important part of computer literacy and practice can help groups from kids to adults in computer classes. In addition, typing tests that check for mistakes while timed check your ability to read quickly and spelling accurately. Comfortability with typing can enhance productivity, increase confidence and aptitude with digital tools, and reduce typing fatigue by reducing the need to look at the keyboard while working. Overall, typing tests are a fun way for people to engage with typing practice that has useful metrics and can enhance your time spent online. 
- language/tools: c++, possible gui tentatively (such as qt)
- input - user typing  /// output - score for game, accuracy percentage, words per minute output, most commonly missed chracters, most frequent errors
features
- typing feedback/analysis : determine metrics such as typing speed, accuracy, common errors, avg time to complete passage (based on modes)
- different test modes: timed passage, how many words can be typed in a minute or two minutes or other time periods, multiple difficulties of passages, blind typing (where user input is hidden for the duration of the test), themed passages
- shooting for fun game modes: timed mode (ex: type given word in 5 seconds to get a point, three failed attempts ends game), race against bot
- try for basic gui if enough time: echo text as user types next to passage and color code green/red for correct or incorrect spelling

## User Interface Specification

### Navigation Diagram
![navigation diagram](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/blob/bb4ab4319fce4d7f2b4634e841d7ce294341fc95/Typing%20Project%20User%20Interface%20Specification%20(2).png)

### Screen Layouts
![IMG_0581](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/117537259/5597d20c-4809-49e6-adfe-8eac9e41eb0a)
![screen diagram](screenlayout1.jpg)
![screen diagram](screenlayout2.jpg)
The screen layout for this typing program starts with a main menu that the users can choose from, (i.e. create / edit profile , benchmark gamemode , attrition and quit) which the user change navigate through the interface by using numbers located in front of the options. Users can set up profiles with having the options to create or pick an existing profile in which can be created by simply typing in a name to assign / save with the profile in which stats will be respective to its profiles, and users can switch back and forth deciding what profiles to use. Moreover, the users can have the ability to play a benchmark mode in which the user can pick a numbered words prompt (i.e. 10, 25, 50 words). Additionally, after finishing the prompt the users will be presented with statistics such as Duration, WPM, Accuracy, and # of Errors of the user's current test. ==Furthermore, afterwards once the user finishes a particular option will then be presented back to the main menu where they will be given the same main menu as it was initially starting the tests.

## Class Diagram
![uml diagram](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/79384814/71a7bc84-38ce-4152-8d0c-ecf3c9a334b4)
This is the current version of our uml diagram. At the top is the word namespace (shown as a uml package) which will house all of the various helper functions for reading in text from a .txt file and storing it as either a string or a vector<string> depending on the mode. Our mode is the base class which will take in a username (login) and check to see if it is already present. If it is, it will load that profile and if not, it will create a new profile. The profile class is the composite of the stats class and this will contain all of the stats that will be measured in all of the modes (wpm, accuracy, errors, etc.). In addition to the stats, the profile will have a specific username associated with it to facilitate different users. To that end, it has a writeProfile() and readProfile() method which will write user info to a file and read it in respectively. Going back to the mode class, it has other basic functions such as calculating the accuracy, errors and wpm that will be used in all three derived classes. The last shared function is the TextDisplay() method which will display our text screen for the tests. The first derived class is our benchmark mode which will output different passages based on the type and word count. It will then start a timer and measure how long it takes the user to input the passage correctly recording errors as it goes. The next derived class is a life-based game mode. It will keep a score based on how many words are finished before time runs out using the timedWord() method and the setScore() method. The timedWord() function will track if the user can type in a word in a certain time interval and take away lives every time the user fails. This class uses a wordList which is a vector of strings and will be generated from functions in the word namespace. The final class is the botRace class which will randomly generate a wpm to use for the bot. It will then compare the time you take to finish the passage to the bot and write the win/loss record. 
 
## Phase III
![solid uml](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/79384814/5df854b8-f42c-4b52-af2b-ab5568a0b90d)
First, we updated our mode and profile class to be more independent of each other following the SRP principle because our profile class which we wanted to use to keep everything contained together was dependent on the mode class to store/read usernames and to add/delete profiles. We put all username/profile related tasks inside the profile. To help out, we added a new FileManager class following the SRP principle. To add new features such as file-related saving/reading, we put it in a new specific class. Overall, this helped streamline the code because we were able to isolate the profile code and get that working on its own. Similarly, the mode class was changed to be focused purely on running the different tests instead of also having to manage profiles. This made it a ModeSelect class which is only focused on storing stats and starting the different modes. In theory, this should make it more efficient to keep track of the game flow/logic of switching between modes while retaining the stats which was a major flaw of the previous uml setup. The next change we made was adding a set of stat-calculator classes following the SRP principle. THis allowed us to remove all of the stat related functions from our game modes. This change should allow us to work on the stat calculator class along with the actual stats class and make sure it works so that each game mode simply has to call the stat calculator class instead of doing it all within one class. The different stat calculator classes are to fulfill the open/closed or interface segregation principle because each game mode requires slightly different additions to the stat calculator and we don't want a benchmark statCalculator to have to implement a score function for example. Hopefully, this streamlines the stats aspect of our app by keeping it contained in a couple related classes that we can work on and test without needing to run the entire game mode. Our final change was adding a text display class following the SRP principles. This allowed us to combine all of the related display functions into one mode that will have slight variations depending on the mode chosen. Thus, we would only have to write one code for outputting user input alongside the passage and it can be used for all three game modes. 

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
