import subprocess

informe_name = "informe"
informe_directorio = "informe/"

make_pdf_command = "pdflatex " + "-output-directory informe " + informe_name + ".tex"
# move_pdf_command = "mv " + informe_directorio + informe_name + ".pdf " + informe_name + ".pdf"
open_pdf_command = "evince " + informe_directorio + informe_name + ".pdf"

subprocess.call(make_pdf_command.split())
# subprocess.call(move_pdf_command.split())
subprocess.call(open_pdf_command.split())