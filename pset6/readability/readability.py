from cs50 import get_string

def main():
    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = (letters / words) * 100.0
    S = (sentences / words) * 100.0

    grade = round(0.0588 * L - 0.296 * S - 15.8)

    if grade >= 16:
        print("Grade: 16+")
    if grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")
    return



def count_letters(text):
    sum = 0

    for char in text:
        if char.isalpha():
            sum += 1
    return sum


def count_words(text):
    return len(text.split())

def count_sentences(text):
    sum = 0
    sentence_endings = ".!?"

    for i in range(0, len(text)):
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            sum += 1
    return sum

# def get_text():
#     while True:
#         text = get_string("Text: ")
#         if (text[0]) not 0:
#             break
#     return text


main()

