import subprocess

# Template file to include algorithms latex packages
# The problem was that you cannot include external packages in jupyter engine
# Solution was just write latex imagining I had the packages, 
# and then compile the pdf manually using this template to insert the packages declaration

template_file = "jupyter/template_jupyterpdf.tplx"
notebook_name = "Informe"
notebook_path = "jupyter/" + notebook_name

convert_jupyter_command = "jupyter nbconvert " + notebook_path  + ".ipynb" +  " --to latex " + "--template " + template_file
make_pdf_command = "pdflatex " + "-output-directory jupyter " + notebook_path + ".tex"

move_pdf_command = "mv " + notebook_path + ".pdf " + notebook_name + ".pdf"

subprocess.call(convert_jupyter_command.split())

# Para la entrega final, modificar a mano el .tex para hacer una bonita caratula
subprocess.call(make_pdf_command.split())
subprocess.call(move_pdf_command.split())