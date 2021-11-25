# Introduction

The exam system gives you assignments one by one, and will grade you on-demand when you ask it to.

An exam is a set of levels, and each level has its pool of possible assignments that are given at random. Your neighbor probably won't have the same as you. Life is unfair, deal with it.

For each level you validate, you'll get points, up to a maximum of 100.

## Before the exam

Before doing an exam, you will have to subscribe to (or retry, if it isn't the first time) at least one exam project on the Intranet. You can subscribe to as many as you like, there are no restrictions about this.

Once you're subscribed to at least one exam project, you will be able to access it using `examshell`, but only in practice mode.

If you want to do it for real, you also have to subscribe to an exam session, be at the session ON TIME, and login as "exam" in the exam room. Only then will you be able to do the exam in real mode.

## Exam modes

There are two exam modes :

* Practice mode, that you can access from your own session, from anywhere, anytime. In practice mode, everything works normally except your grade will not be taken into account on the Intranet. You can practice an exam as often as you like.
* Real mode, that you can only access from the "exam" session, in an exam room, during an exam event. In this mode, your grade WILL be counted on the Intranet, and if you end your session your grade will become definitive.

## Examshell

You will interface with the exam system using a program called `examshell`.

You have to start it yourself in its own terminal, at the latest 10 minutes after the exam start date. If you stop it inadvertently, it's not a problem, you can just start it again by typing `examshell` in a terminal. It will just resume the process to where it was before.

# Short version

1. You start examshell
2. Examshell tells you the different exams you have access to
3. You choose an exam and a starting level
4. The system creates a Git repository for you and clones is to BASEDIR/rendu
5. The system chooses a random assignment for you in the current level
6. Examshell downloads the subject for the assignements to BASEDIR/subjects/ASSIGNMENT_NAME/
7. Examshell tells you what assignment you're supposed to do, how many points you stand to win, and where you should turn it in
8. You work on your assignment
9. You push your assignment on the Git repository as usual
10. You are sure you're finished: You tell examshell to grade you using the `grademe` command
11. The system grades your assignment
12. Examshell saves the grading trace to BASEDIR/traces/ASSIGNMENT_TRACE_DIR
13. If you succeeded, you will gain points and go up one level. If there are levels left in the exam, goto 5, else the exam is finished
14. If you failed, you stay at the same level, lose 5 potential points, and goto 5. If there are no more assignments in the current level's pool, the exam is finished.

Don't get it ? Read the long version !

# Long version

We'll do an example for this documentation, running in practice mode. When running in real mode, you will work in `~/`, but in practice we work in `~/exam-basedir/`.

## Step 1: Starting examshell

```
zaz@blackjack ~ $ examshell
examshell v0.1.1

WARNING
Your exam files will be stored in ~/exam-basedir
THIS DIRECTORY WILL BE ENTIRELY EMPTIED BEFORE YOU START
So, if you do have important things there, Ctrl-C NOW and back them up before running this.
(Press Enter to continue...)
```

This warning is absolutely normal. It's just to make sure you don't already have a `~/exam-basedir/` directory with stuff you care about, because examshell will completely empty it. This is so we can have a "clean" exam directory to work in.

If this was in real mode, the warning wouldn't be there.

## Step 2: Choosing an exam

When you login, use examshell to choose an exam you want to do, and the level you wish to start at. You can only start at a level you have already validated once for this exam.

```
[...]
Getting current exam session from server...

The following projects are available to you at the moment:

  0 : Exam C
      Maximum start level    : 4 (Best grade you got is 75)
      Real mode available    : no (You must subscribe to an exam event)
      Practice mode available: yes (Ends in 4 hours, 0 minutes and 0 seconds)

There is only one project you can do right now.
Automatically selecting project 0: "Exam C"

This project can only be done in practice mode
In 'practice' mode, your grade will not be taken into account, and you can only access your repository from your regular (non-exam) session

Please select the level at which you would like to start your session
Be aware that if you select a level higher than 0, you will only gain however many points the previous levels would have given you IF you complete your selected starting level !

Desired start level (0-4):
```

If there's more than one available exam, you will choose one, of course.

For this example, we will start at level 0. If it doesn't ask you which level you want to start at, don't panic, it's just that you can't start at another level than 0 for the exam you chose.

```
[...]
Desired start level (0-4): 0

You are about to start the project "Exam C", in practice mode, at level 0.
You would have 4 hours, 0 minutes and 0 seconds to complete this project
Confirm ? [y/n]
```

If for any reason you're not sure that's what you want to do, just type `n` and you will be able to choose again.

Note that if you have to restart examshell for any reason after you have selected the project, it will of course not ask you to choose again. It will go straight to step 3.


## Step 3: Preparing the work directory

After you confirm, examshell will prepare the working directory (`~/exam-basedir/` in practice mode, `~/` in real mode), clone the appropriate Git repository, etc...

```
[...]
Confirm ? [y/n] y
Selecting project...
Creating required directories...
Ensuring your Git repository for this exam is present and correct...
Git repository is not cloned yet. Cloning...
Cloning into '/Users/zaz/exam-basedir/rendu'...
vogsphere: (INFO) Transaction ID : 8ed938b3-fe1e-4eb6-b561-0f6622e12b82
vogsphere: (INFO) Please mention this ID in any ticket you create concerning this transaction
vogsphere: (INFO) This transaction has been started at 2015-05-28 11:07:49, server time.
vogsphere: (INFO) Rights will be determined using this time, so do NOT cut the connection.
vogsphere: (INFO) It appears you are mmontinet. If that's not true, check your Kerberos tickets (klist)
vogsphere: (INFO) You have read and write rights on this repository
warning: You appear to have cloned an empty repository.

Your git repository was successfully cloned to ~/exam-basedir/rendu

The following commands are available to you:
  status: Displays the status of your session, including information about
    your current assignment, and the exam history.
  grademe: Asks the server to grade your current assignment. If you
    have done it right, you will gain the points of the current assignment, go
    up a level, and try the next one. If you fail, however, you will have
    another assignment of the same level to do, and it will potentially bring
    you less points on your grade ... So be sure of yourself before you launch
    this command !
  finish: Tells the server you are finished with your exam.

You can log out at any time. If this program tells you you earned points,
then they will be counted whatever happens.

(Press Enter to continue...)
```

## Step 4: Getting an assignment

Examshell will now fetch your current assignment from the system.

It will automatically save the subject in the `subjects` directory. You can read it in a terminal.

```
[...]
================================================================================
You are currently at level 0
You are running in practice mode (Your grade does not count)
Your current grade is 0/100
Assignments:
  Level 0:
    0: max for 16 potential points (Current)

Your current assignment is max for 16 potential points
It is assignment 0 for level 0
The subject is located at: ~/exam-basedir/subjects/max
You must turn in your files in a subdirectory of your Git repository with the
same name as the assignment (~/exam-basedir/rendu/max).
Of course, you must still push...

The end date for this exam is: 28/05/2015 15:07:47
You have 3 hours, 54 minutes and 11 seconds remaining
================================================================================
You can now work on your assignment. When you are sure you're done with it,
push it to vogsphere, and then use the "grademe" command to be graded.
examshell>
```

This display is always accessible using the `status` command.

## Step 5: Work on your assignment

Now, well, you do the work you are assigned.

Note that you HAVE to turn it in in the directory examshell told you, which is a subdirectory of the Git repository with the same name as the assignment. No typos, no anything. If you use the wrong directory, you will fail the assignment, with no option to go back. That'd be bad.

In our example, we would put our `max.c` file in `~/exam-basedir/rendu/max/`.

You WILL have to push your work after you're done, as with any regular project, so don't forget !

## Step 6: Request to be graded

Once you're SURE that your work is done correctly, and that you have pushed it to vogsphere, you can use the `grademe` command to request that your assignment be graded:

```
examshell> grademe

Before continuing, please make ABSOLUTELY SURE that you have pushed your files,
that they are in the right directory, that you didn't forget anything, etc...
If your assignment is wrong, you will have another assignment at the same level,
but with less potential points to earn!

Are you sure? [y/N]
```

So, yeah, let's say we're sure.

```
[...]

Are you sure? [y/N] y
OK, making grading request to server now.

We will now wait for the job to complete.
Please be patient, this CAN take several minutes...
(10 seconds is fast, 30 seconds is expected, 3 minutes is a maximum)
waiting...
```

Now we wait for the system to grade us. It actually CAN take some time, but that's expected, so don't panic unless you wait for 1-2 minutes, in which case you should just ask a staff member, it's an easy fix.

### Success !

```
[...]
waiting...
>>>>>>>>>> SUCCESS <<<<<<<<<<
You have successfully completed the assignment and earned 16 points!
Trace saved to ~/exam-basedir/traces/0-0_max.trace

(Press Enter to continue...)
```

In this case, we succeeded. The grading trace is automatically saved for us to read if we want.

The next status message will show that:

* We earned the points in play for the assignment (16)
* We have gone up a level (now at 1)
* We have a new assignment

```
[...]
(Press Enter to continue...)

================================================================================
You are currently at level 1
You are running in practice mode (Your grade does not count)
Your current grade is 16/100
Assignments:
  Level 0:
    0: max for 16 potential points (Success)
  Level 1:
    0: wdmatch for 16 potential points (Current)

Your current assignment is wdmatch for 16 potential points
It is assignment 0 for level 1
The subject is located at: ~/exam-basedir/subjects/wdmatch
You must turn in your files in a subdirectory of your Git repository with the
same name as the assignment (~/exam-basedir/rendu/wdmatch).
Of course, you must still push...

The end date for this exam is: 28/05/2015 15:07:47
You have 3 hours, 42 minutes and 27 seconds remaining
================================================================================
You can now work on your assignment. When you are sure you're done with it,
push it to vogsphere, and then use the "grademe" command to be graded.
examshell>
```

If that had been the last level of the exam, examshell would have said it, and told us the exam was finished.

### Failure :(

Let's fail this one, just to see what it does:

```
[...]
examshell> grademe

Before continuing, please make ABSOLUTELY SURE that you have pushed your files,
that they are in the right directory, that you didn't forget anything, etc...
If your assignment is wrong, you will have another assignment at the same level,
but with less potential points to earn!

Are you sure? [y/N] y
OK, making grading request to server now.

We will now wait for the job to complete.
Please be patient, this CAN take several minutes...
(10 seconds is fast, 30 seconds is expected, 3 minutes is a maximum)
waiting...
>>>>>>>>>> FAILURE <<<<<<<<<<
You have failed the assignment.
Trace saved to ~/exam-basedir/traces/1-0_wdmatch.trace

(Press Enter to continue...)

================================================================================
You are currently at level 1
You are running in practice mode (Your grade does not count)
Your current grade is 16/100
Assignments:
  Level 0:
    0: max for 16 potential points (Success)
  Level 1:
    0: wdmatch for 16 potential points (Failure)
    1: ft_strrev for 11 potential points (Current)

Your current assignment is ft_strrev for 11 potential points
It is assignment 1 for level 1
The subject is located at: ~/exam-basedir/subjects/ft_strrev
You must turn in your files in a subdirectory of your Git repository with the
same name as the assignment (~/exam-basedir/rendu/ft_strrev).
Of course, you must still push...

The end date for this exam is: 28/05/2015 15:07:47
You have 3 hours, 41 minutes and 25 seconds remaining
================================================================================
You can now work on your assignment. When you are sure you're done with it,
push it to vogsphere, and then use the "grademe" command to be graded.
examshell>
```

In this case, we failed, so :

* We do NOT get the points
* We do NOT go up a level (we stay at 1)
* We get a new assignment, but with 5 less points to gain !

If that had been the last possible assignment in this level, examshell would have said it, and told us the exam was finished.

### Error :<

There is the possibility that examshell says the grading resulted in an ERROR. This does not mean you failed, it means that
the grading system itself has failed.

However, don't panic !

You will have the option to either retry or abort. You SHOULD retry at least once, because errors in the grading system are rare,
and usually transient, so they'd resolve with a retry. If a retry does not solve the error, get a staff member to help !

If all else fails, then you can abort. This would give you another assignment of the same level, but without losing potential
points.

## Step 7: Let's go again

That's basically it. You will continue getting new assignments until either you fail enough assignments to exhaust a level's pool of assignments, or you succeed at the last level of the exam.

If you want, you can end your session at any time by using the `finish` command.

```
examshell> finish
Please confirm that you REALLY want to end your current session.
If you do, you will not be able to do anything with it anymore!
Are you finished? [y/N] y
Your session has been marked as finished. You may now log out.
zaz@blackjack ~ $
```

# FAQ / Common errors

## I stopped examshell, what do I do ?

Just start it again, it's no big deal.

## Examshell tells me the "login window expired", what gives ?

You have 10 minutes to choose an exam after the exam start date, afterwards you will get this error because it's simply too late.
No, you can not do anything about it.

## Examshell tells me "Mismatched versions", what gives ?

The machine you are on is probably just not updated yet. Either switch to another computer, or come to the Bocal and ask us to update it.

## Why can't I use real mode // practice mode ?

Examshell tells you exactly why. Here are the possible reasons:

* "Can't practice when logged in as 'exam'"
	* You have to login using your regular session to use practice mode
* "Project doesn't allow it"
	* This means the exam project in itself forbids using a specific mode. You can't do anything about that.
* "You must subscribe to an exam event"
	* As said in the introduction, to do the exam in real mode, you have to be subscribed to an exam session on the intranet. You can do that in your calendar.
* "You must retry the project on the intranet"
	* You can not use real mode if you haven't retried the project on the intranet, because the system wouldn't be able to give you a grade for it.
* "Current event doesn't allow for this exam"
	* Some exams are restricted to specific sessions. Most notably during a "piscine". You will have to attend a session that's made specifically for this exam
* "Can't do it from this location"
	* Most exams are restricted to a specific location so that the exam is done under controlled conditions. You have to login at one of these places ! Practice mode, however, is available from anywhere
* "Too early, well be OK in XXX" // "Too late, ended at XXX"
	* Means the closest exam session you are subscribed to is not yet started or has already ended.
* "Must login as 'exam' to run in real mode"
	* Pretty self-explanatory, isn't it ? Just login as "exam" with password "exam".

## I didn't have the same assignments as my neighbor, it's unfair !

Yes. Too bad. Deal with it.

## Can I access my repository after the exam ? What about the subjects ?

Normally, you'll get an email with all of this after the exam is marked as finished.

If you didn't ... well, wait. If you really don't receive it, too bad, life is unfair I guess.

## Examshell told me I failed, but I'm sure I didn't !

Most likely, you just forgot something :

* Did you push ?
* Really ?
* Did you use the right directory ?
* Are all your files named correctly ?
* Did you even do the right assignment ?
* Did you REALLY push ?
* Etc...

If you are really, really, REALLY, ABSOLUTELY sure you have done it right, and that the system fucked you, well, just come tell the staff AFTER THE EXAM. We will look at it, but please, please, please think before you come see us : It really is most likely it's your fault, and it takes us a long time to try to look for an error in the assignment itself.

## Your system sucks, I want the old one !

No it doesn't, and no you can't have it back.

## I found a bug in the system !

Really ?

Well, if you did, please tell us. We won't get mad at you if you don't exploit it.

## I found a bug in the system, and I exploited it, you guys will never catch me !

Yes we will. At some point ! And we hope you'll enjoy looking for another school :)

Seriously, don't be an idiot, just report it and move on. It's not worth getting fired for a few points on an exam, is it ?

## Examshell tells me I waited too long to choose a project, what gives ?

Nothing's wrong, just try again. It really isn't an error, it's just examshell's clumsy way of telling you you're too indecisive.

## I've made a grading request but it takes a long time

Well, does it actually finish at some point ? If it's still not finished after, say, a minute or two, just go get a staff member, because it's not really normal, but it's normally an easy fix for us.

## Why is practice forbidden in an exam session ?

Because I said so.

## I have another question and it's not listed here, this FAQ is useless !

Good for you. Just come ask us and we'll add it, we can't think of everything without at least some drugs to help us.
