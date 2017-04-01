import subprocess

# Template file to include algorithms latex packages
# The problem was that you cannot include external packages in jupyter engine
# Solution was just write latex imagining I had the packages, 
# and then compile the pdf manually using this template to insert the packages declaration

template_file = "jupyter/use_algorithms_latex_packs.tplx"
notebook_name = "test"
notebook_path = "jupyter/" + notebook_name

convert_jupyter_command = "jupyter nbconvert " + notebook_path  + ".ipynb" +  " --to latex " + "--template " + template_file
make_pdf_command = "pdflatex " + notebook_path + ".tex"

subprocess.call(convert_jupyter_command.split())
subprocess.call(make_pdf_command.split())

