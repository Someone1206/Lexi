import os
import sys


if __name__ == '__main__':
    for arg in sys.argv:
        if not os.path.exists(arg):
            os.makedirs(arg)