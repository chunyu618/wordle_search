
# Reference: http://www.mieliestronk.com/wordlist.html
filename = 'corncob_lowercase.txt'

def main():
    with open(filename, 'r') as f:
        data = f.readlines()
        five_letter_words = []
        for word in data:
            word = word.split()[0]
            if len(word) == 5:
                five_letter_words.append(word)

        for word in five_letter_words:
            print(word)
        print(len(five_letter_words))


if __name__ == '__main__':
    main()
