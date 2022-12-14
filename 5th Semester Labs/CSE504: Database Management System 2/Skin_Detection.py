import numpy as np
import cv2
import imageio
import matplotlib.pyplot as plt

########################## TRAINING ##########################

# Probabiltiy of Color if the image contain SKIN, P(C|S)
color_probability_in_skin_img = np.empty(shape=(256, 256, 256)).fill(0.0)
# Probabiltiy of Color if the image contain NON-SKIN, P(C|NS)
color_probability_in_non_skin_img = np.empty(shape=(256, 256, 256)).fill(0.0)

# Count each of 256^3 comobinition of color in SKINNED Image
rgb_tuple_frequency_skin_img = np.empty(shape=(256, 256, 256)).fill(0)
# Count each of 256^3 comobinition of color in SKINNED Image
rgb_tuple_frequency_non_skin_img = np.empty(shape=(256, 256, 256)).fill(0)

# P(C|S) /  P(C|NS) = P(S|C) / P(NS|C) ==  Probability of C (color) to be a SKIN Color
skin_color_probability = np.empty(shape=(256, 256, 256)).fill(0.0)


total_images = 350
indices = ["%04d" % x for x in range(1000)]
total_pixel = 0
skin_pixels = 0
non_skin_pixels = 0


for index in range(total_images):
    mask_image = cv2.imread("ibtd/Mask/"+str(indices[index])+".bmp")
    actual_image = cv2.imread("ibtd/"+str(indices[index])+".jpg")

    height, width, channel = mask_image.shape
    total_pixel += height*width

    for x in range(height):
        for y in range(width):
            blue = mask_image[x, y, 0]
            green = mask_image[x, y, 1]
            red = mask_image[x, y, 2]

            if (blue > 250 and green > 250 and red > 250):  # means it's NON-SKIN
                blue = actual_image[x, y, 0]
                green = actual_image[x, y, 1]
                red = actual_image[x, y, 2]

                rgb_tuple_frequency_non_skin_img[red, green, blue] += 1
                non_skin_pixels += 1
            else:
                rgb_tuple_frequency_skin_img[red, green, blue] += 1
                skin_pixels += 1

    print("Image ", index, " - DONE!")


for r in range(256):
    for g in range(256):
        for b in range(256):
            color_probability_in_skin_img[r, g, b] = rgb_tuple_frequency_skin_img[r, g, b]/skin_pixels
            color_probability_in_non_skin_img[r, g, b] = rgb_tuple_frequency_non_skin_img[r, g, b]/non_skin_pixels

            if (rgb_tuple_frequency_non_skin_img[r, g, b] != 0):
                skin_color_probability[r, g, b] = rgb_tuple_frequency_skin_img[r, g, b] / \
                    rgb_tuple_frequency_non_skin_img[r, g, b]
            else:
                skin_color_probability[r, g, b] = 0.0   


########################## TESTING ##########################

print("Testing image...")

input_img = "sample3.jpg"
output_img = "final3.jpg"
new_img = np.empty(shape=(256, 256, 256), dtype=int)
new_img.fill(0)

new_img = imageio.imread(input_img)

height, width, channel = new_img.shape
T = 0.4

for x in range(height):
    for y in range(width):
        red = new_img[x, y, 0]
        green = new_img[x, y, 1]
        blue = new_img[x, y, 2]

        if (skin_color_probability[red, green, blue] > T):
            continue
        else:
            # image without skin is covered with BLACK
            new_img[x, y, 0] = 0
            new_img[x, y, 1] = 0
            new_img[x, y, 2] = 0

plt.imsave(output_img, new_img)
