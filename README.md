# C++ testing with Google Test in XCode via CMake

Since 1986, I often return to C++ even though I stopped full time use of it in
1996 when I went to Java. An audio developer really cannot avoid it.

My current projects are on iOS using a mixture of Swift, Objective-C, and C++.
This is pretty normal for iOS audio project, btw. The problem is, I wasn't doing
that thing I always did in server side Java - testing.

Testing the first two in XCode is pretty much built in. So I have good coverage
of that code. But C++. No such luck. You have to do something else.

It turns out that there are a zillion C++ testing frameworks available. One is
Google Test (or Google Mock with which Test merged). Another is Boost's
[Boost.Test framework](https://www.boost.org/doc/libs/1_68_0/libs/test/doc/html/index.html).
But let's start with Google.

For the first several months, I just updated my XCode build settings. That works
if you get it right. I could make an XCode template - my others are on Github -
but you have to be in the right mood to tackle their awful format.

So, CMake seems to be popular :)

Well, here it is.

There are several ways to integrate Google Test via CMake. The one with the
least capability of making you look like an idiot (my daily goal) is here.
This is discussed over at [Google
Test](https://github.com/google/googletest/blob/master/googletest/README.md)

## How to
There is a minimal shell script to generate an XCode project. Run it and a
directory named *macos* will be created. Open the XCode project from there.

Easy, huh?

## Postlude

My directories are set up like a Maven project. It makes sense to me.
You don't have to do this.
Just update CMakeLists.txt to point at your directories.
