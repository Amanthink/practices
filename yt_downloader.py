import os
import zipfile
from yt_dlp import YoutubeDL

# ==== CONFIG ====
PLAYLIST_URL = "https://youtube.com/playlist?list=PLmXKhU9FNesR1rSES7oLdJaNFgmuj0SYV&si=CG0NZ37RojP3VtA3"
DOWNLOAD_FOLDER = "downloads"
ZIP_NAME = "playlist.zip"

# Create download folder
os.makedirs(DOWNLOAD_FOLDER, exist_ok=True)

# yt-dlp options
ydl_opts = {
    'outtmpl': f'{DOWNLOAD_FOLDER}/%(playlist_index)s - %(title)s.%(ext)s',
    'format': 'bestvideo+bestaudio/best',
    'merge_output_format': 'mp4',
    'ignoreerrors': True,
}

print("Downloading playlist...")

# Download playlist
with YoutubeDL(ydl_opts) as ydl:
    ydl.download([PLAYLIST_URL])

print("Download complete. Creating ZIP...")

# Create ZIP file
with zipfile.ZipFile(ZIP_NAME, 'w', zipfile.ZIP_DEFLATED) as zipf:
    for root, dirs, files in os.walk(DOWNLOAD_FOLDER):
        for file in files:
            filepath = os.path.join(root, file)
            zipf.write(filepath, arcname=file)

print(f"ZIP created: {ZIP_NAME}")