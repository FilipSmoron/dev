import random

class Question:
    def __init__(self, text, options, correct_option):
        self.text = text
        self.options = options
        self.correct_option = correct_option

    def is_correct(self, answer):
        return answer == self.correct_option

class Quiz:
    def __init__(self, questions):
        self.questions = questions
        self.score = 0

    def run_quiz(self):
        for index, question in enumerate(self.questions, start=1):
            print(f"\nQuestion {index}: {question.text}")
            random.shuffle(question.options)

            for i, option in enumerate(question.options, start=1):
                print(f"{i}. {option}")

            user_answer = input("Your answer (enter the number): ")
            if user_answer.isdigit():
                user_answer = int(user_answer)

                if 1 <= user_answer <= 4:
                    if question.is_correct(question.options[user_answer - 1]):
                        print("Correct!")
                        self.score += 1
                    else:
                        print(f"Wrong! The correct answer was: {question.correct_option}")
                else:
                    print("Invalid input. Please enter a number between 1 and 4.")
            else:
                print("Invalid input. Please enter a number.")

        print(f"\nQuiz completed. Your score: {self.score}/{len(self.questions)}")


# Przykładowe pytania
questions = [
    Question("What does HTML stand for?", ["Hyper Text Markup Language", "Hyper Transfer Markup Language", "High Text Markup Language", "Hyperlink and Text Markup Language"], 1),
    Question("What does CSS stand for?", ["Counter Strike: Source", "Corrective Style Sheet", "Computer Style Sheet", "Cascading Style Sheet"], 4),
    # Dodaj tutaj pozostałe pytania
    # ...
]

# Przygotowanie quizu
quiz = Quiz(questions)

# Uruchomienie quizu
quiz.run_quiz()