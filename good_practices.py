# Some sample codes that I find while reading the code

# Read the binary data from input fd and write the data to output fd
def copybinary(input, output):
    BUFSIZE = 8192
    while 1:
        line = input.read(BUFSIZE)
        if not line: break
        output.write(line)

# Read data from a file and write the data to the output fd.
def copyliteral(input, output):
    while 1:
        line = input.readline()
        if not line: break
        output.write(line)

# A pipe to read data of an output of a command executed
# and write it to a file.
def pipethrough(input, command, output):
    (fd, tempname) = tempfile.mkstemp()
    temp = os.fdopen(fd, 'w')
    copyliteral(input, temp)
    temp.close()
    pipe = os.popen(command + ' <' + tempname, 'r')
    copybinary(pipe, output)
    pipe.close()
    os.unlink(tempname)

# Search tree to find the files that match the glob
def search_tree(root, glob_match, ext):
    """Look in root, for any files/dirs matching glob, recurively traversing
    any found directories looking for files ending with ext

    :param root: start of search path
    :param glob_match: glob to match in root, matching dirs are traversed with
                       os.walk
    :param ext: only files that end in ext will be returned

    :returns: list of full paths to matching files, sorted

    """
    found_files = []
    for path in glob.glob(os.path.join(root, glob_match)):
        if path.endswith(ext):
            found_files.append(path)
        else:
            for root, dirs, files in os.walk(path):
                for file in files:
                    if file.endswith(ext):
                        found_files.append(os.path.join(root, file))
    return sorted(found_files)
