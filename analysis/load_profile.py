import numpy as np
import pandas
import argparse
import array
import struct
import sys

parser = argparse.ArgumentParser(description='Load a profile into a database')
parser.add_argument('profile', help='the .out file generated by an instrumented program')
parser-add_argument('db', help='the database in which to load the profile')

def load_profile(path):
    with open(path, 'r') as pf:
        nbbs, nthreads, profile_type = struct.unpack('III', pf.read(12))
        profile_n = nthreads * nthreads * nbbs
        profile = np.fromfile(pf, 'I', profile_n)
        bb_names = pf.read().split("\0")
        if len(bb_names) != nbbs:
            print >> sys.stderr, ("profile reported %d basic blocks but"
                "only %d names were read"%(nbbs, len(bb_names)))
            return None
        return pandas.Series(profile, bb_names)

if __name__ == "__main__":
    args = parser.parse_args()
    print load_profile(args.profile)

