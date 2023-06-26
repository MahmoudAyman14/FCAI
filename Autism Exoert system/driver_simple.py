#driver
import contextlib
import sys
import PySimpleGUI as sg
from pyke import knowledge_engine
from pyke import krb_traceback

engine = knowledge_engine.engine(__file__)


def bc_test():
    engine.reset()  # Allows us to run tests multiple times.

    engine.activate('bc_simple_rules')  # STUDENTS: you will need to edit the name of your rule file here

    print("doing proof")

    try:
        with engine.prove_goal(
                'bc_simple_rules.kind($kind)') as gen:  # STUDENTS: you will need to edit this line
            for vars, plan in gen:
                print("kind: %s" % (vars['kind']))  # STUDENTS: you will need to edit this line
    except Exception:
        # This converts stack frames of generated python functions back to the
        # .krb file.
        krb_traceback.print_exc()
        sys.exit(1)

    print()
    print("done")
    # engine.print_stats()


def bc_test_questions():
    engine.reset()  # Allows us to run tests multiple times.

    engine.activate('bc_simple_rules_questions')  # STUDENTS: you will need to edit the name of your rule file here

    # Define the layout of the GUI
    layout = [[sg.Text('Please answer the following questions:')],
              [sg.Text('Is the patients age from two to four?')],
              [sg.Radio('Yes', 'Age'), sg.Radio('No', 'age')],
              [sg.Text('Did the patient have epilepsy?')],
              [sg.Radio('Yes', 'epilepsy'), sg.Radio('No', 'epilepsy')],
              [sg.Text('Do you have difficulty for making friends?')],
              [sg.Radio('Yes', 'friends'), sg.Radio('No', 'friends')],
              [sg.Text('Do you have selective silence?')],
              [sg.Radio('Yes', 'silence'), sg.Radio('No', 'silence')],
              [sg.Text('Do you have social anxiety?')],
              [sg.Radio('Yes', 'anxiety'), sg.Radio('No', 'anxiety')],
              [sg.Text('Do you have difficulty or severe need for eye contact?')],
              [sg.Radio('Yes', 'eye_contact'), sg.Radio('No', 'eye_contact')],
              [sg.Text('Do you suffer from extreme focus on specific interests?')],
              [sg.Radio('Yes', 'focus'), sg.Radio('No', 'focus')],
              [sg.Text('Do you find patterns and symmetry?')],
              [sg.Radio('Yes', 'patterns'), sg.Radio('No', 'patterns')],
              [sg.Text('Do you stick to the routine?')],
              [sg.Radio('Yes', 'routine'), sg.Radio('No', 'routine')],
              [sg.Text('Do you suffer from any disability?')],
              [sg.Radio('Yes', 'disability'), sg.Radio('No', 'disability')],
              [sg.Text('Do you suffer from language delays?')],
              [sg.Radio('Yes', 'language'), sg.Radio('No', 'language')],
              [sg.Text('Do you have trouble controlling emotions?')],
              [sg.Radio('Yes', 'emotions'), sg.Radio('No', 'emotions')],
              [sg.Text('Do you find it hard to keep up a conversation with people?')],
              [sg.Radio('Yes', 'conversation'), sg.Radio('No', 'conversation')],
              [sg.Text('Do you have a flat voice?')],
              [sg.Radio('Yes', 'voice'), sg.Radio('No', 'voice')],
              [sg.Submit(), sg.Cancel()]
              ]
    window = sg.Window('Autism Test', layout, size=(900, 800),finalize=True)
    window.maximize()

    event, values = window.read()



    file = open("user input.txt", "w")
    for i in values:
        if values[i]:
            if i % 2 == 0:
                ans = 'y'
                file.write(ans + '\n')
            else:
                ans = 'n'
                file.write(ans + '\n')

    file.close()
    window.close()

    try:
        sys.stdin = open("user input.txt")
        for i in ans:
            print(i)
        with engine.prove_goal('bc_simple_rules_questions.kind($kind)') as gen:
            for vars, plan in gen:
                sg.popup("kind: %s" % (vars['kind']))
                break
    except Exception:
        # This converts stack frames of generated python functions back to the
        # .krb file.
        krb_traceback.print_exc()
        sys.exit(1)


bc_test_questions()