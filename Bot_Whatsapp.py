# Necessária instalação de biblioteca. Abra o terminal e digite: pip3 install pywhatkit

import pywhatkit

def mensagem():
    pywhatkit.sendwhatmsg("+5599912345678", "Mensagem", 16, 4, 30)

mensagem()
