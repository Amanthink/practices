#!/usr/bin/env python3
"""
YouTube Playlist MP4 Downloader
================================
Downloads an entire YouTube playlist as MP4 files with one command.

Requirements:
    pip install yt-dlp

Usage:
    python download_playlist.py
    python download_playlist.py --url "https://youtube.com/playlist?list=..." --output "./downloads" --quality 1080
"""

import os
import sys
import argparse
import subprocess

# ─────────────────────────────────────────────
# Auto-install yt-dlp if missing
# ─────────────────────────────────────────────
try:
    import yt_dlp
except ImportError:
    print("[*] yt-dlp not found. Installing...")
    subprocess.check_call([sys.executable, "-m", "pip", "install", "yt-dlp", "-q"])
    import yt_dlp
    print("[✓] yt-dlp installed successfully.\n")


# ─────────────────────────────────────────────
# Progress hook
# ─────────────────────────────────────────────
def progress_hook(d):
    if d["status"] == "downloading":
        filename = os.path.basename(d.get("filename", ""))
        percent  = d.get("_percent_str", "??%").strip()
        speed    = d.get("_speed_str", "?? KiB/s").strip()
        eta      = d.get("_eta_str", "??s").strip()
        print(f"\r  ↓ {filename[:50]:<50}  {percent:>6}  @ {speed:<12}  ETA {eta}   ", end="", flush=True)

    elif d["status"] == "finished":
        print(f"\n  [✓] Downloaded: {os.path.basename(d['filename'])}")

    elif d["status"] == "error":
        print(f"\n  [✗] Error downloading: {d.get('filename', 'unknown')}")


# ─────────────────────────────────────────────
# Core downloader
# ─────────────────────────────────────────────
def download_playlist(url: str, output_dir: str, quality: int, skip_existing: bool):
    os.makedirs(output_dir, exist_ok=True)

    # Format: best video up to chosen height + best audio, merged to MP4
    format_str = f"bestvideo[height<={quality}][ext=mp4]+bestaudio[ext=m4a]/bestvideo[height<={quality}]+bestaudio/best[height<={quality}]/best"

    ydl_opts = {
        # Output template: folder / playlist_index - title.mp4
        "outtmpl": os.path.join(output_dir, "%(playlist_index)s - %(title)s.%(ext)s"),
        "format": format_str,
        "merge_output_format": "mp4",
        "noplaylist": False,          # ensure whole playlist is fetched
        "ignoreerrors": True,         # skip unavailable videos
        "noprogress": False,
        "progress_hooks": [progress_hook],
        "postprocessors": [
            {
                "key": "FFmpegVideoConvertor",
                "preferedformat": "mp4",
            }
        ],
        "quiet": False,
        "no_warnings": False,
        # Skip already-downloaded files
        "nooverwrites": skip_existing,
        "continuedl": True,
    }

    print(f"\n{'='*60}")
    print(f"  YouTube Playlist Downloader")
    print(f"{'='*60}")
    print(f"  URL       : {url}")
    print(f"  Output    : {os.path.abspath(output_dir)}")
    print(f"  Quality   : up to {quality}p")
    print(f"  Skip done : {skip_existing}")
    print(f"{'='*60}\n")

    with yt_dlp.YoutubeDL(ydl_opts) as ydl:
        info = ydl.extract_info(url, download=False)
        if not info:
            print("[✗] Could not fetch playlist info. Check the URL and try again.")
            sys.exit(1)

        playlist_title = info.get("title", "Unknown Playlist")
        entries        = info.get("entries", [])
        count          = len([e for e in entries if e])  # filter None (private/deleted)

        print(f"  Playlist  : {playlist_title}")
        print(f"  Videos    : {count}\n")

        # Confirm before downloading
        confirm = input("  Start downloading? [Y/n]: ").strip().lower()
        if confirm not in ("", "y", "yes"):
            print("  Aborted.")
            sys.exit(0)

        print()
        ydl.download([url])

    print(f"\n{'='*60}")
    print(f"  [✓] All done!  Files saved to: {os.path.abspath(output_dir)}")
    print(f"{'='*60}\n")


# ─────────────────────────────────────────────
# CLI entry point
# ─────────────────────────────────────────────
def parse_args():
    parser = argparse.ArgumentParser(
        description="Download a YouTube playlist as MP4 files.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  python download_playlist.py
  python download_playlist.py --url "https://youtube.com/playlist?list=PLxxx" --quality 720
  python download_playlist.py --url "..." --output "D:/Movies" --quality 1080 --no-skip
        """,
    )
    parser.add_argument(
        "--url", "-u",
        type=str,
        default=None,
        help="YouTube playlist URL (prompted if not provided)",
    )
    parser.add_argument(
        "--output", "-o",
        type=str,
        default="./downloads",
        help="Folder to save MP4 files (default: ./downloads)",
    )
    parser.add_argument(
        "--quality", "-q",
        type=int,
        default=1080,
        choices=[360, 480, 720, 1080, 1440, 2160],
        help="Max video height in pixels (default: 1080)",
    )
    parser.add_argument(
        "--no-skip",
        action="store_true",
        default=False,
        help="Re-download files even if they already exist",
    )
    return parser.parse_args()


def main():
    args = parse_args()

    url = args.url
    if not url:
        url = input("  Enter YouTube Playlist URL: ").strip()
    if not url:
        print("[✗] No URL provided. Exiting.")
        sys.exit(1)

    download_playlist(
        url=url,
        output_dir=args.output,
        quality=args.quality,
        skip_existing=not args.no_skip,
    )


if __name__ == "__main__":
    main()