# Text Scramble
 
> Authors: [Brandon Vo](https://github.com/bxnvo)
> [Matthew Chun](https://github.com/matthwchun)
> [Randall Nguyen](https://github.com/1rwen)
> [Willa Ralston](https://github.com/chairfu)

## Project Description
This is important because it develops useful skills for coding such as accuracy and speed which is useful for completing tasks quickly. Furthermore, typing is an important part of computer literacy and practice can help groups from kids to adults in computer classes. In addition, typing tests that check for mistakes while timed check your ability to read quickly and spelling accurately. Comfortability with typing can enhance productivity, increase confidence and aptitude with digital tools, and reduce typing fatigue by reducing the need to look at the keyboard while working. Overall, typing tests are a fun way for people to engage with typing practice that has useful metrics and can enhance your time spent online. 
features
- language/tools: c++, possible gui tentatively (such as qt)
- input - user typing
- typing feedback/analysis : determine metrics such as accuracy percentage, words per minute , number of errors, total duration, score for attrition, test count
- different test modes: different # words prompts, multiple difficulties of passages, themed passages, attrition mode (user has a limited number of lives)
- output : terminal based program, navigation through character input

## User Interface Specification

### Navigation Diagram
![navigation diagram](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/blob/8b5bb2fbc4e77cc6a51c7f5398dbfe70166c412b/Typing%20Project%20User%20Interface%20Specification.png)

### Screen Layouts
![IMG_0589](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/117537259/ef10f96e-58d4-4cd3-ab16-0d5ec42ad2e0)
![IMG_0590](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/117537259/d0543e9c-594c-40c4-99c6-4bca288f2e42)
The screen layout for this typing program starts with a main menu where the users has a selection to choose from (i.e., profile editor, benchmark gamemode , attrition, stats mode, and quit), which the user can navigate through the interface by using the assign character in front of the options. Users can set up profiles by having the option to create or pick an existing profile, which can be created by simply typing in a name to assign or save with the profile, whose stats will be respective to its profiles, and users can switch back and forth between deciding what profiles to use. Moreover, the users can have the ability to play a benchmark mode in which they can pick a numbered word prompt (i.e., 10, 25, or 50 words) with a selection of different variations of the number of words prompt, such as different themes / difficulty. Afterwards, after finishing the prompt, the users will be presented with statistics such as time duration, WPM, accuracy, and the number of errors in the user's current test. Furthermore, a similar layout is also applied to attrition mode, where the user is given a number of lives in which words will pop up on the screen, and the user has to keep going until eventually they get a number of words incorrect, at which point the program will end giving the user's statistics (i.e. duration, wpm, accuracy, attrition score); like in benchmark mode, the user has a selection of different variations of prompts (i.e. difficulty, themes) that the user can choose from. The last main menu option is the stats history, where the user has the opportunity to look at their most recent run, overall average stats, or best run, showcasing in each selection the respective stats. Furthermore, once the user finishes a particular option, they will be presented back to the main menu, where they will be given the same main menu as when they were initially starting the tests, in which the user can decide to quit or play another gamemode.

## Class Diagram
![Lucidchart Blank Diagram](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/79384814/648769e7-0630-432f-b701-698fabee86af)

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
 Before any presented with any options, a user must create and/or select a profile.
 
 ![image](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/124600164/6d89e163-94f6-4042-93f3-2ace7cd70f7b)

 The user is then presented with a main menu that allows them to take tests, view stats, or manage their profile(s).

 ![image](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/124600164/167ecbcd-de27-474a-95c3-eb99961ec441)

 Upon entering the profile editor:

 ![image](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/124600164/7b381999-fd92-4f04-ae3e-56f8ca997da4)

 The user may select a different profile,

 ![image](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/124600164/d8ab3bcc-7605-4869-9c78-01f9be7c8e83)

 change their current username,

 ![image](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/124600164/67feea47-cc32-4ceb-a384-8df41c3bdc4d)

 create a new profile,

 ![image](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/124600164/d8d7a005-03a1-4a4f-8113-6fb6cc2a723e)

 delete a profile (and if the profile to delete is currently selected, select a different one),
 
 ![image](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/124600164/04a692f8-4f69-48b2-aef6-9c4ff673ef39)

 see a list of all profiles,

 ![image](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/124600164/f7bf3d97-8cff-47cf-910f-9ebfac523b6a)

 write their current stats (of their choice) to a file,

 ![image](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/124600164/162545f8-32c0-4d9f-a480-199ae559a19f)

 or display the stats they stored.

 ![image](https://github.com/cs100/final-project-rnguy137-mchun082-bvo024-wrals001/assets/124600164/cae1cd48-c30a-4078-a366-dd38e355df46)


 ## Installation/Usage
- git clone https://www.chegg.com/homework-help/questions-and-answers/red-ball-mass-210-g-constant-force-pushes-red-ball-horizontally-launches-speed-20-m-s-forc-q86684535
- afterwards, the user should then change directory by "cd src"
- to execute "g++ -pthread main.cpp ModeSelect.cpp Attrition.cpp Benchmark.cpp ProfileUpdater.cpp ProfileManager.cpp TextDisplay.cpp words.cpp stats.cpp -o typingTest"
 ## Testing
 We used a combination of unit testing and manual behavioral testing.  Our unit tests were used to verify calculations and program flow, as well as provide a repeatable method for testing.  We also used manual behavioral testing to cover edge cases and any other cases that we might've missed in our unit tests (this was necessary due to our program's dependency on user input).  To check our data files, we just manually opened the file and kept track of any edits or deletions.  
 
