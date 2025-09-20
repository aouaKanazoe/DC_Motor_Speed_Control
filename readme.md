
# 🚀 Projet de Contrôle d’un Moteur DC avec Encodeur sous Simulink & Arduino

## 📌 Description du projet
Ce projet a pour objectif de mettre en œuvre l’asservissement en vitesse d’un moteur à courant continu équipé d’un **encodeur incrémental**, en utilisant **Simulink** et une **Arduino Uno** comme cible embarquée.  

Le système permet de :
- Lire la position fournie par l’encodeur.
- Calculer la vitesse de rotation (en **RPM**).
- Appliquer un **filtrage passe-bas** pour réduire le bruit de mesure.
- Réguler la vitesse du moteur autour d’une consigne grâce à un **contrôleur PID**.
- Générer un signal **PWM** adapté pour piloter le pont en H (L298N).

---

## ⚙️ Architecture Simulink
Le modèle est structuré en plusieurs sous-systèmes :  

1. **Encoder**  
   - Lecture des impulsions de l’encodeur via les pins digitales de l’Arduino.  
   - Stockage de la valeur courante et de la valeur précédente pour le calcul de la vitesse.  

2. **Calculate RPM**  
   - Différence entre la valeur courante et la précédente de l’encodeur.  
   - Conversion en tours par minute (RPM).  

3. **Low-Pass Filter**  
   - Filtrage du signal de vitesse brute pour lisser les fluctuations rapides.  
   - Paramètres ajustables (gain et constante de temps).  

4. **PID Controller**  
   - Comparaison entre la consigne de vitesse (Target RPM) et la vitesse mesurée (RPM filtrée).  
   - Calcul du signal de commande (PWM).  
   - Réglage des coefficients **Kp, Ki, Kd** via un bloc de tuning.  

5. **PWM Output**  
   - Génération du signal PWM envoyé au driver de puissance (L298N).  
   - Commande directe du moteur DC.  

---

## 🖥️ Matériel utilisé
- **Arduino Uno**
- **Moteur DC** équipé d’un **encodeur incrémental**
- **Driver L298N** (pont en H)
- **Alimentation 12 V DC** adaptée au moteur


![figure](https://github.com/aouaKanazoe/DC_Motor_Speed_Control/blob/master/docs/Hardware_Overview.png)

![figure](https://github.com/aouaKanazoe/DC_Motor_Speed_Control/blob/master/docs/montage_de_test.jpg)

![figure](https://github.com/aouaKanazoe/DC_Motor_Speed_Control/blob/master/docs/schema_simulink_asservissement_PID_DCmotor.png)

