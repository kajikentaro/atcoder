# Base Docker image for AtCoder
build:
	cd infra && docker buildx build --platform linux/amd64,linux/arm64 -t kajindowsxp/atcoder:1.0.0 --push .

# Docker Image with ssh server
# ID: aaa
# Pass: printed in the console after executing `docker run`
build-ssh:
	cd infra/ssh && docker buildx build --platform linux/amd64,linux/arm64 -t kajindowsxp/atcoder:ssh-1.0.0 --push .
