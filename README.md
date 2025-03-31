# AskMe

AskMe is a simple console-based simulation of the ASKfm platform. You can sign up, log in, ask people questions (anonymously or not), and answer questions you get. It also keeps track of everything you do so you can come back to it later.

I built this to practice object-oriented programming in C++, and to structure things in a way that makes the code easy to extend and maintain.

## What it does

- Lets you **create an account** and log in
- Ask questions to any user, either **anonymously** or with your name
- Answer questions people ask you
- See all the questions you've asked or received, grouped by thread
- View a public **question feed**
- Keeps your data saved between runs (accounts, questions, answers, etc.)

## How it works

The whole project is split into a few classes, each handling a different part of the system:

- `account` – handles user info like username, password, and their questions
- `question` – stores info about who asked what, if it was anonymous, and so on
- `answer` – links answers to their questions
- `_ACCOUNTS_`, `_QUESTIONS_`, `_ANSWERS_` – manage everything related to accounts, questions, and answers respectively
- `_SYSTEM_` – ties everything together and runs the main program loop

Everything is stored in memory while running and written to files so the data sticks around next time you run it.

## Why I made it

Honestly, I just wanted to practice building something a bit more realistic using classes and OOP in C++. I thought simulating something like ASKfm would be a fun way to do that.

---
