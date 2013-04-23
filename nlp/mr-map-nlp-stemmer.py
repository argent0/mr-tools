#!/usr/bin/env python2
# -*- coding: utf-8 -*-
import nltk.stem.snowball
import sys
import re
from kitchen.text.converters import getwriter

UTF8Writer = getwriter('utf8')
sys.stdout = UTF8Writer(sys.stdout)

stemer = nltk.stem.snowball.SpanishStemmer(True)

if __name__ == "__main__":
	line = sys.stdin.readline().strip()
	while line:
		line = unicode(line,'utf8')
		line = re.sub(r'\n','',line)

		parts = line.split('\t')
		if len(parts) < 2:
			sys.stderr.write("Skipping valueless line:"+line+"\n")
		else:
			[key, value] = line.split('\t')

			words = value.split()
			#nonstop = [ re.sub(r'[^a-zA-Zó ]','',w.lower().strip()) for w in words if w not in stemer.stopwords ]
			nonstop = [ re.sub(r'[^A-Za-z\xe9\xe1\xed\xf3\xfa\xf1]','',w.lower().strip()) for w in words if w not in stemer.stopwords ]
			#print [ stemer.stem(w) for w in nonstop ]
			value = u' '.join(set([ stemer.stem(w) for w in nonstop]))

			if len(value)>0:
				print key+"\t"+value
				#sys.stdout.write(key+"\t"+value+"\n");
			else:
				sys.stderr.write("Skipping void value of line:"+line+"\n")

		line = sys.stdin.readline().strip()
