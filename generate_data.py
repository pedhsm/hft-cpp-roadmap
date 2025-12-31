import csv
import random
import time

def gerar_market_data():
    filename = "market_data.csv"
    num_lines = 1_000_000 
    tickers = ["PETR4", "VALE3", "ITUB4", "BBDC4", "WDOUT", "WINUT"]
    
    print(f"Gerando {num_lines} linhas no arquivo '{filename}'...")
    start = time.time()

    with open(filename, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["Ticker", "Price", "Size", "Timestamp"])
        
        batch = []
        batch_size = 10_000
        
        for i in range(num_lines):
            t = random.choice(tickers)
            p = round(random.uniform(10.50, 120.00), 2)  
            s = random.randint(1, 100) * 100            
            ts = 1700000000 + i                         
            
            batch.append([t, p, s, ts])
            
            if len(batch) >= batch_size:
                writer.writerows(batch)
                batch = []
        
        if batch:
            writer.writerows(batch)

    end = time.time()
    print(f"Concluido em {end - start:.2f} segundos!")

if __name__ == "__main__":
    gerar_market_data()