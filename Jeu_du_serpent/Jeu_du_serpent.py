import pygame
import random 


pygame.init()
L = 640
H = 480
window_resolution = (L, H)
pygame.display.set_caption("Jeu du serpent")
window_surface = pygame.display.set_mode(window_resolution)
clock = pygame.time.Clock()
fichier_nom = "score.txt"

vert = (0, 255, 0)
rouge = (255, 0, 0)
blanc = (255, 255, 255)
noir = (0, 0, 0)
vx = 0
vy = 0
longueur = 1
score = 0
taille_bloc = 20
vitesse = taille_bloc
taille_police = 20
f = open(fichier_nom, "r")
high_score = int(f.read())
f.close()
score_texte = "Score : "
high_score_texte = "Meilleur score : "
serpent_couleur = vert
texte_couleur = blanc
pomme_couleur = rouge

arial_font = pygame.font.SysFont("Arial", taille_police)
high_score_surface = arial_font.render(high_score_texte + str(high_score), False, texte_couleur)

def dessiner_serpent(serpent):
    for case in serpent:
        pygame.draw.rect(window_surface, serpent_couleur, pygame.Rect(case[0], case[1], taille_bloc, taille_bloc))  
    

def apparition_pomme():
    x = random.randrange(0, 640 - taille_bloc, taille_bloc)
    y = random.randrange(0, 480 - taille_bloc, taille_bloc)
    pomme = pygame.Rect(x, y, taille_bloc, taille_bloc)
    return pomme



pomme = apparition_pomme()
x = L/2
y = H/2
serpent = [(x,y)]
launched = True
while launched :
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            launched = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP and vy == 0:
                vy = -vitesse
                vx = 0
            elif event.key == pygame.K_DOWN and vy == 0:
                vy = vitesse
                vx = 0
            elif event.key == pygame.K_LEFT and vx == 0:
                vx = -vitesse
                vy = 0
            elif event.key == pygame.K_RIGHT and vx ==0:
                vx = vitesse
                vy = 0  
        
    x += vx
    y += vy
    serpent.append((x,y))

    if len(serpent) > longueur:
        serpent.pop(0)

    if x < 0 or x >= L or y < 0 or y >= H or (x,y) in serpent[:-1]:
        if score > high_score :
            f = open(fichier_nom, "w")
            f.write(str(score))
            f.close()
        launched = False 
    
    if (x, y) == (pomme.x, pomme.y):
        longueur +=1
        score +=1
        pomme = apparition_pomme()

    window_surface.fill(noir)
    dessiner_serpent(serpent)
    pygame.draw.circle(window_surface, pomme_couleur, (pomme.x + taille_bloc/2, pomme.y + taille_bloc/2), taille_bloc/2)
    score_surface = arial_font.render(score_texte + str(score), False, texte_couleur)
    window_surface.blit(score_surface, [0,0])
    window_surface.blit(high_score_surface, [0,20])
    pygame.display.flip()
    clock.tick(10)



