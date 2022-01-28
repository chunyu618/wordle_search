# wordle_search

A C++ program that help to play [wordle](https://www.powerlanguage.co.uk/wordle/).

Search a word based on pattern and excluded characters.

## Complie and execute

#### Step 1

```
$ git clone https://github.com/chunyu618/wordle_search.git
```



#### Step 2

Download **[Mieliestronk's English list](http://www.mieliestronk.com/corncob_lowercase.txt)** and separate $5$ letter words from it.

```
& wget http://www.mieliestronk.com/corncob_lowercase.txt
& python3 build.py
```



#### Step 3

First compile the C++ program

```
$ make
```

Then excecute it

```
$ ./search
```

You can see teh usage.
