import numpy as np
import cv2

# probability of P(C|S) and P(C|NS)
color_in_skin = np.empty(shape=(256, 256, 256))
color_in_skin.fill(0.0)

color_in_non_skin = np.empty(shape=(256, 256, 256))
color_in_non_skin.fill(0.0)

# Count of Skin Colors
skin_rgb = np.empty(shape=(256, 256, 256))
skin_rgb.fill(0)

# Count of Non-Skin Colors
non_skin_rgb = np.empty(shape=(256, 256, 256))
non_skin_rgb.fill(0)

# P(C|S) /  P(C|NS)
color_ratio = np.empty(shape=(256, 256, 256))
color_ratio.fill(0.0)

skin_cnt = 0
non_skin_cnt = 0


total_images = 555
indices = ["%04d" % x for x in range(1000)]
total_pixel = 0


for index in range(total_images):
    mask_image = cv2.imread("ibtd/Mask/"+str(indices[index])+".bmp")
    actual_image = cv2.imread("ibtd/"+str(indices[index])+".jpg")

    height, width, channel = mask_image.shape

    for x in range(height):
        for y in range(width):
            blue = mask_image[x, y, 0]
            green = mask_image[x, y, 1]
            red = mask_image[x, y, 2]

            if (blue > 250 and green > 250 and red > 250):  # means it's NON-SKIN
                blue = actual_image[x, y, 0]
                green = actual_image[x, y, 1]
                red = actual_image[x, y, 2]

                non_skin_rgb[red, green, blue] += 1
                non_skin_cnt += 1
            else:
                skin_rgb[red, green, blue] += 1
                skin_cnt += 1
                

    print("Image ", index, " - DONE!")


fp = open('output.txt', 'w')
for r in range(256):
    for g in range(256):
        for b in range(256):
            color_in_skin[r,g,b] = skin_rgb[r,g,b]/skin_cnt
            color_in_non_skin[r,g,b] = non_skin_rgb[r,g,b]/non_skin_cnt

            if (non_skin_rgb[r, g, b] != 0):
                color_ratio[r, g, b] = color_in_skin[r, g, b] / \
                    color_in_non_skin[r, g, b]
            else:
                color_ratio[r, g, b] = 0.0

            tmp = color_ratio[r, g, b]
            fp.write(f"{tmp}\n")
            
fp.close()
