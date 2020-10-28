import re
from glob import glob

def min_c(src):
	lines = src.split("\n")
	out = ""
	i = 0
	cont = False
	while i < len(lines):
		l = lines[i].split("//")[0];
		l = re.sub(r'\/\*.*?\*\/','',l);
		if (not len(l.strip())):
			i+=1
			continue

		if l.strip()[-1] == '\\':
			cont = True
			l = l.strip()[0:-1]

		if (l.strip()[0] == '#'):
			out += "\n"
			out += l.strip()
			if not cont:
				out += "\n"

		elif cont:
			out += " "
			out += l.strip()

		else:
			if not len(l[0].strip()) or l.strip()[0] == '}':
				out += l.strip()
			else:
				out += "\n"
				out += l.strip()
			
		if lines[i].split("//")[0].strip()[-1] != '\\':
			cont = False

		i+=1
	out = out.replace("\n\n","\n").replace("\n\n","\n").strip()
	return out

def min_wax(src):
	return src.replace("\n"," ").strip()

def min_java(src):
	return min_c(src)

def min_cs(src):
	return min_c(src)

def min_cpp(src):
	return min_c(src)

def min_ts(src):
	return src.replace("\n\n","\n");

def min_py(src):
	return src.replace("\n\n","\n");

def min_lua(src):
	return src.replace("\n\n","\n");
	
def min_swift(src):
	return src.replace("\n\n","\n");


def to_cstr(src):
	return '"'+src.replace('"','\\"').replace("\n",'\\n"\n"')+'\\n"'


paths = glob("../src/std/std.*")+glob("../src/std/*.wax")

out = "/*GENERATED BY TOOLS/CONCAT.PY (DO NOT EDIT)*/\n#ifndef WAX_STD_TEXT\n#define WAX_STD_TEXT\n"
for p in paths:
	p = p.replace('\\','/')
	ext = p.split(".")[-1]
	f = open(p,'r').read()
	g = globals()['min_'+ext](f)
	h = to_cstr(g)
	name = "TEXT_"+p.split("/")[-1].replace("/","_").replace("\\","_").replace(".","_")
	out += "const char* "+name+" = "+h+";\n"
out += "\n#endif\n"

open("../src/text.c",'w').write(out)
