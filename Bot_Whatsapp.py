from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.common.exceptions import NoSuchElementException, NoSuchAttributeException, TimeoutException
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as ec
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.keys import Keys
import pandas as pd
import xlsxwriter
from time import sleep
from colorama import Fore, Style


class Bot_Whatsapp:
    
    def __init__(self):
        self.iniciar_driver()
        self.acessar_site()

    def iniciar_driver(self):
        try:
            options = webdriver.ChromeOptions()
            options.add_experimental_option('excludeSwitches', ['enable-logging'])
            service = Service('C:/Users/UFCA/Downloads/chromedriver-win64/chromedriver-win64/chromedriver.exe')  # Especifique AQUI o caminho para o chromedriver, com esse mesmo formato.
            self.driver = webdriver.Chrome(service=service, options=options)
        
        except Exception as ex:
            print(f"{Fore.RED}Erro ao tentar iniciar o Chromedriver.{Fore.RESET}\n"
                    f"Verifique se especificou o caminho para o chromedriver corretamente no método 'iniciar_driver'.\n"
                    f"Em caso positivo, veja se a versão é"
                    f" compatível com sua versão do Google Chrome.\nErro do tipo: {type(ex).__name__}")
            quit()


    def acessar_site(self):

        df = pd.read_excel("mensagens.xlsx", sheet_name="Planilha1")
        contatos = df["Numero"].to_list()
        mensagens = df["Mensagem"].to_list()

        self.driver.get('https://web.whatsapp.com/')
        WebDriverWait(self.driver, 40).until(
            ec.element_to_be_clickable(
                (By.XPATH, '//*[@id="app"]/div/div/div[4]/header/div[2]/div/span/div[3]/div')))
        sleep(2)
        botao_iniciar_conversa = self.driver.find_element(By.XPATH, '//*[@id="app"]/div/div/div[4]/header/div[2]/div/span/div[3]/div')

        for i in range(len(mensagens)):

            botao_iniciar_conversa.click()
        
            WebDriverWait(self.driver, 40).until(
                ec.element_to_be_clickable(
                    (By.XPATH, '//*[@id="app"]/div/div/div[3]/div[1]/span/div/span/div/div[1]/div/div[2]/div/div[1]')))
            sleep(2)
            caixa_de_texto = self.driver.find_element(By.XPATH, '//*[@id="app"]/div/div/div[3]/div[1]/span/div/span/div/div[1]/div/div[2]/div/div[1]')
            caixa_de_texto.send_keys(contatos[i])
            sleep(5)

            contato = self.driver.find_element(By.XPATH, '//*[@id="app"]/div/div/div[3]/div[1]/span/div/span/div/div[2]/div[2]')
            contato.click()
            caixa_de_texto = self.driver.find_element(By.XPATH, '//*[@id="main"]/footer/div[1]/div/span[2]/div/div[2]/div[1]/div/div[1]')
            caixa_de_texto.send_keys(mensagens[i])
            caixa_de_texto.send_keys(Keys.ENTER)
            sleep(3)


Bot = Bot_Whatsapp()
