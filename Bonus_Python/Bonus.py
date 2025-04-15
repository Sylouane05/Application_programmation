import pygame

# Initialisation
pygame.init()
window_resolution = (640, 480)
window_surface = pygame.display.set_mode(window_resolution)
pygame.display.set_caption("Bonus")
clock = pygame.time.Clock()

# Couleurs
green = (0, 255, 0)
red = (255, 0, 0)
blue = (0, 0, 255)
jaune= (255, 255, 0)
white = (255, 255, 255)
black = (0, 0, 0)

# Police & texte
arial = pygame.font.SysFont("Arial", 30)
vivant = "Sylouane est vivant !"
mort = "Sylouane est mort !"
etat_sylouane = arial.render(vivant, False, blue)

# Sons
blaster = pygame.mixer.Sound("Blaster_star_wars_long.ogg")
wilhelm_sound = pygame.mixer.Sound("Cri wilhelm.ogg")

# Images
#mort_image = pygame.image.load("mort.png")
#mort_image.convert_alpha()

# Rectangles
block_fusil1 = pygame.Rect(40, 100, 50, 50)
block_fusil2 = pygame.Rect(90, 100, 70, 10)
balle = pygame.Rect(150, 100, 10, 10)
tete_sylouane = pygame.Rect(500, 90, 50, 50)
corps_sylouane = pygame.Rect(500, 150, 50, 80)
pied_gauche_sylouane = pygame.Rect(500, 230, 20, 50)
pied_droit_sylouane = pygame.Rect(530, 230, 20, 50)

# État
launched = True
droite = 3
sylouane_mort = False

# Lancer le son du blaster une fois au début
blaster.play()



# Boucle principale
while launched:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            launched = False

    # Déplacement de la balle
    balle.x += droite
    

    # Si Sylouane est touché
    if balle.colliderect(tete_sylouane) and not sylouane_mort:
        sylouane_mort = True
        blaster.stop()  # Arrête le son du blaster
        wilhelm_sound.play()
        etat_sylouane = arial.render(mort, False, red)
        droite = 0
        
       

    # Nettoyage écran
    window_surface.fill(black)

    # Dessin
    pygame.draw.rect(window_surface, red, block_fusil1)
    pygame.draw.rect(window_surface, red, block_fusil2)
    pygame.draw.rect(window_surface, red, balle)
    

    couleur = red if sylouane_mort else green
    pygame.draw.rect(window_surface, couleur, tete_sylouane)
    pygame.draw.rect(window_surface, couleur, corps_sylouane)
    pygame.draw.rect(window_surface, couleur, pied_gauche_sylouane)
    pygame.draw.rect(window_surface, couleur, pied_droit_sylouane)
    #window_surface.blit(mort_image, [500, 90]) if sylouane_mort else None
    window_surface.blit(etat_sylouane, [20, 20])

    pygame.display.flip()
    clock.tick(100)


