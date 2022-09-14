from xml.dom import InuseAttributeErr
import cv2
import numpy
import time
import random


    ## 1 rectangle par touche : tous les pixels du rectangle doivent être colorés pour capter une note.
    ## nb.: le rectangle d'une touche # chevauche celui d'une touche naturelle
list_of_sources = [
    ((0, 460, 32, 5)),     # A  1
    ((25, 440, 20, 5)),    # A# 1
    ((35, 460, 35, 5)),    # B  1
    ((70, 460, 35, 5)),    # C  1
    ((90, 440, 20, 5)),    # C# 1
    ((107, 460, 35, 5)),   # D  1
    ((132, 440, 20, 5)),   # D# 1
    ((145, 460, 35, 5)),   # E  1
    ((180, 460, 35, 5)),   # F  1
    ((200, 440, 20, 5)),   # F# 1
    ((215, 460, 35, 5)),   # G  1
    ((240, 440, 20, 5)),   # G# 1

    ((255, 460, 35, 5)),   # A  2
    ((282, 440, 20, 5)),   # A# 2
    ((290, 460, 35, 5)),   # B  2
    ((330, 460, 35, 5)),   # C  2
    ((350, 440, 20, 5)),   # C# 2
    ((370, 460, 35, 5)),   # D  2
    ((393, 440, 20, 5)),   # D# 2
    ((405, 460, 35, 5)),   # E  2
    ((460, 460, 35, 5)),   # F  2
    ((460, 440, 20, 5)),   # F# 2
    ((480, 460, 35, 5)),   # G  2
    ((502, 440, 20, 5)),   # G# 2

    ((515, 460, 35, 5)),   # A  3
    ((545, 440, 20, 5)),   # A# 3
    ((555, 460, 35, 5)),   # B  3
    ((590, 460, 35, 5)),   # C  3
    ((610, 440, 20, 5)),   # C# 3
    ((630, 460, 35, 5)),   # D  3
    ((655, 440, 20, 5)),   # D# 3
    ((665, 460, 35, 5)),   # E  3
    ((705, 460, 35, 5)),   # F  3
    ((723, 440, 20, 5)),   # F# 3
    ((740, 460, 35, 5)),   # G  3
    ((765, 440, 20, 5)),   # G# 3

    ((780, 460, 35, 5)),   # A  4
    ((808, 440, 20, 5)),   # A# 4
    ((815, 460, 35, 5)),   # B  4
    ((855, 460, 35, 5)),   # C  4
    ((875, 440, 20, 5)),   # C# 4
    ((890, 460, 35, 5)),   # D  4
    ((920, 440, 20, 5)),   # D# 4
    ((930, 460, 35, 5)),   # E  4
    ((970, 460, 35, 5)),   # F  4
    ((985, 440, 20, 5)),   # F# 4
    ((1005, 460, 35, 5)),  # G  4
    ((1030, 440, 20, 5)),  # G# 4

    ((1045, 460, 35, 5)),  # A  5
    ((1070, 440, 20, 5)),  # A# 5
    ((1080, 460, 35, 5)),  # B  5
    ((1120, 460, 35, 5)),  # C  5
    ((1140, 440, 20, 5)),  # C# 5
    ((1155, 460, 35, 5)),  # D  5
    ((1182, 440, 20, 5)),  # D# 5
    ((1190, 460, 35, 5)),  # E  5
    ((1230, 460, 35, 5)),  # F  5
    ((1250, 440, 20, 5)),  # F# 5
    ((1270, 460, 35, 5)),  # G  5
    ((1290, 440, 20, 5)),  # G# 5

    ((1305, 460, 35, 5)),  # A  6
    ((1332, 440, 20, 5)),  # A# 6
    ((1340, 460, 35, 5)),  # B  6
    ((1440, 460, 35, 5)),  # C  6
    ((1460, 440, 20, 5)),  # C# 6
    ((1415, 460, 35, 5)),  # D  6
    ((1442, 440, 20, 5)),  # D# 6
    ((1450, 460, 35, 5)),  # E  6
    ((1490, 460, 35, 5)),  # F  6
    ((1510, 440, 20, 5)),  # F# 6
    ((1525, 460, 35, 5)),  # G  6
    ((1550, 440, 20, 5)),  # G# 6

    ((1565, 460, 35, 5)),  # A  7
    ((1590, 440, 20, 5)),  # A# 7
    ((1600, 460, 35, 5)),  # B  7
    ((1635, 460, 35, 5)),  # C  7
    ((1655, 440, 20, 5)),  # C# 7
    ((1675, 460, 35, 5)),  # D  7
    ((1700, 440, 20, 5)),  # D# 7
    ((1705, 460, 35, 5)),  # E  7
    ((1745, 460, 35, 5)),  # F  7
    ((1765, 440, 20, 5)),  # F# 7
    ((1780, 460, 35, 5)),  # G  7
    ((1802, 440, 20, 5)),  # G# 7

    ((1815, 460, 35, 5)),  # A  8
    ((1845, 440, 20, 5)),  # A# 8
    ((1850, 460, 35, 5)),  # B  8
    ((1890, 460, 30, 5)),  # C  8
]

def note_pressed(capt, frame):
    for x in range(list_of_sources[capt][0], list_of_sources[capt][0] + list_of_sources[capt][2], 1):
        for y in range(list_of_sources[capt][1], list_of_sources[capt][1] + list_of_sources[capt][3], 1):
##         affiche les rectangles capteurs :
            frame[y][x] = (((255. / 12.) * (capt % 12), (255. / 12.) * (capt % 12), 50))
#            if frame[y][x][0] < 200 and frame[y][x][1] < 200 and frame[y][x][2] < 200:
#                return False
    return True


def open_video():
    video_name = "moonlight-sonata_1st-movement_Beethoven.webm"
    cap = cv2.VideoCapture(video_name)
    if cap.isOpened() == False:
        print("Error opening video file \"", video_name, "\"")
        exit()
    return cap

def open_output():
    output_file = open("output.txt", 'w')
    return output_file

def play(cap, output):
    nb_keys = len(list_of_sources)
    notes = [0] * 95
    partition = []

    while cap.isOpened():
        partition += [notes]

        ret, frame = cap.read()

        for capt in range(nb_keys):
            if note_pressed(capt, frame):
                output.write('1')
                partition[len(partition) - 1][capt] = 1
            else:
                output.write('0')
                partition[len(partition) - 1][capt] = 0

        output.write('\n')

        cv2.imshow('output', frame)
        if(cv2.waitKey(1) & 0xFF == ord('q')):
            break

    cap.release()

def main():
    play(open_video(), open_output())
    cv2.destroyAllWindows()

main()