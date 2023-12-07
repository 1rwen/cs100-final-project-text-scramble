
#include "Benchmark.h"

#include "gtest/gtest.h"

using namespace std;

// accuracy

TEST(BenchmarkTest, IncompleteAccuracyTest) {
  Benchmark Test1;

  string user_string = ""; 

  ifstream file("10-words-prompt.txt");

  // Open the file
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  string prompt;

  getline(file, prompt);

  EXPECT_EQ(Test1.calcAccuracy("10-words-prompt.txt", user_string), 0.0);
  
}

TEST(BenchmarkTest, FlawlessAccuracyTest) {
  Benchmark Test2;

  string user_string = "few here she both should take develop stand govern leave"; 

  ifstream file("10-words-prompt.txt");

  // Open the file
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  string prompt;

  getline(file, prompt);

  EXPECT_EQ(Test2.calcAccuracy(prompt, user_string), 100.0);
  
}

// errors 

TEST(BenchmarkTest, ZeroErrorsTest) {
  Benchmark Test2;

  string user_string = "few here she both should take develop stand govern leave"; 

  ifstream file("10-words-prompt.txt");

  // Open the file
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  string prompt;

  getline(file, prompt);

  Test2.addErrors(prompt, user_string);

  EXPECT_EQ(Test2.getErrors(), 0);
  
}

TEST(BenchmarkTest, AllErrorsTest) {
  Benchmark Test2;

  string user_string = ""; 

  ifstream file("25-words-prompt.txt");

  // Open the file
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  string prompt;

  getline(file, prompt);

  Test2.addErrors(prompt, user_string);

  EXPECT_EQ(Test2.getErrors(), 122); // there's 122 characters within the 25 words prompt
  
}

TEST(BenchmarkTest, IncompleteErrorsTest) {
  Benchmark Test2;

  string user_string = "before or wehre ask on must given then off very play be govern follow small a vut home good than grrat make when wird form"; 

  ifstream file("25-words-prompt.txt");

  // Open the file
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  string prompt;

  getline(file, prompt);

  Test2.addErrors(prompt, user_string);

  EXPECT_EQ(Test2.getErrors(), 5);
  
}

// wpm

TEST(BenchmarkTest, SpamWPMTest) { // 25 words prompt user has to type in 30 seconds to accomplish 50 WPM
  Benchmark Test2;

  string user_string = "before or where ask on must given then off very play be govern follow small a but home good than great make when word form"; 

  ifstream file("25-words-prompt.txt");

  // Open the file
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  string prompt;

  getline(file, prompt);

  duration<double> WPM = duration<double>(duration<double>(25.0) / (duration<double>(30.0) / duration<double>(60.0)));

  //cout << wpm.count() << endl;
  
  EXPECT_EQ(Test2.getWPM(), duration<double>(0.0));
  
}

TEST(BenchmarkTest, SlowWPMTest) { // 25 words prompt user has to type in 30 seconds to accomplish 50 WPM
  Benchmark Test2;

  string user_string = "before or where ask on must given then off very play be govern follow small a but home good than great make when word form"; 

  ifstream file("25-words-prompt.txt");

  // Open the file
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  string prompt;

  getline(file, prompt);

  duration<double> WPM = duration<double>(duration<double>(25.0) / (duration<double>(30.0) / duration<double>(60.0)));

  EXPECT_EQ(WPM, duration<double>(50.0));
  
}

TEST(BenchmarkTest, AverageWPMTest) { // 25 words prompt user has to type in 20 seconds to accomplish 75 WPM
  Benchmark Test2;

  string user_string = "before or where ask on must given then off very play be govern follow small a but home good than great make when word form"; 

  ifstream file("25-words-prompt.txt");

  // Open the file
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  string prompt;

  getline(file, prompt);

  duration<double> WPM = duration<double>(duration<double>(25.0) / (duration<double>(20.0) / duration<double>(60.0)));

  EXPECT_EQ(WPM, duration<double>(75.0));
  
}

TEST(BenchmarkTest, FastWPMTest) { // 25 words prompt user has to type in 15 seconds to accomplish 100 WPM
  Benchmark Test2;

  string user_string = "before or where ask on must given then off very play be govern follow small a but home good than great make when word form"; 

  ifstream file("25-words-prompt.txt");

  // Open the file
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  string prompt;

  getline(file, prompt);

  duration<double> WPM = duration<double>(duration<double>(25.0) / (duration<double>(15.0) / duration<double>(60.0)));

  EXPECT_EQ(WPM, duration<double>(100.0));
  
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}