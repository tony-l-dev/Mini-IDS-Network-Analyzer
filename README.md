# Mini-IDS-Network-Analyzer

capture : 
    - S'occupe de récupérer les paquets réseau
    - Fournit les paquets bruts aux autres modules
    - Décision à prendre : libpcap ou RAW sockets

parser :
    - Extrait les informations essentielles de chaque paquet :
        - IP source/destination
        - Ports source/destination (TCP/UDP)
        - Protocole (TCP, UDP, ICMP)
        - Taille du paquet
    - Fournit une structure de données uniforme pour l'analyse

agg :
    - Compte : top IP, top ports, volume total
    - Maintient des tableaux ou tables de hachages simples

detect (mini-IDS) :
    - Analyse le flux de paquets et détecte : 
        - Brute-force SSH / scans sur port 22
        - Scan de ports
        - Flood ICMP ou TCP
    - Déclenche des alertes sir les seuils sont dépassés

report : 
    - Affiche les informations dans le terminal : 
        - Top IP/ ports / protocoles / trafic
        - Alertes générées
    - Eventuellement écrit un log texte ou JSON pour debug

main :
    - Orchestration : initialise les modules, boucle principale
    - Connecte capture -> parser -> agg -> detect -> report

