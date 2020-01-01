#! /Users/kolodzey/python/shell-python/bin/python

import argparse
from plumbum.cmd import cp

PROBLEM_TEMPLATE_PATH = "/Users/kolodzey/code/cp/cp-code/cli/problem"

parser = argparse.ArgumentParser(description='Create cp problem template.')
parser.add_argument('name', nargs='+', help='problem name')
args = parser.parse_args()

cp["-r", PROBLEM_TEMPLATE_PATH, args.name]()
